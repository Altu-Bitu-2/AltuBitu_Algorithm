#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e8;

vector<bool> visited; //방문 검사 배열
vector<vector<int>> matrix; //비용 행렬
int n, ans = INF; //최소 비용 저장 위해 미리 최댓값으로 초기화

/**
 * !생각해보기! 함수의 각 인자는 각각 어떤 역할을 하고 있나요?
 */
void backtracking(int cnt, int cur_city, int cost) { //cnt는 방문한 도시의 갯수,cur_city는 현재 위치한 도시, cost는 비용
    if (cost >= ans) { //생각해보기 : 이 조건문이 없으면 어떻게 될까요? - 비용이 최소 비용보다 크면 X
        return;
    }
    if (cnt == n) { //종료 조건 : n개의 도시를 순회했음
        //출발 도시(0)로 다시 돌아올 수 있는지 확인
        if (matrix[cur_city][0] != 0) {
            ans = min(ans, cost + matrix[cur_city][0]); //이전 결과 값과 비교하여 더 작은 값 ans에 저장
        }
        return;
    }
    for (int i = 0; i < n; i++) { //cur_city에서 도시 i로 이동
        if (matrix[cur_city][i] && !visited[i]) { //길이 있고, 아직 방문하지 않은 도시
            visited[i] = true; //i번 도시 방문 ->visited의 i번째 인덱스 true로 변경
            backtracking(cnt + 1, i, cost + matrix[cur_city][i]); //방문한 도시 +1, 이동한 도시(i번 도시),i번째 도시로 이동하는데 든 cost 더해준 인자 전달
            visited[i] = false; //방문 기록 초기화
        }
    }
}

/**
 * 백트래킹 풀이 (4ms)
 *
 * 한 사이클을 만들면, 어느 도시에서 시작하든 값은 같으므로 0번 도시부터 시작하는 경우만 검사하면 된다.
 */

int main() {
    //입력
    cin >> n; //도시의 수 입력받기
    visited.assign(n, false); //방문 여부 저장하는 배열 도시의 수 만큼 공간 할당 후 false로 초기화
    matrix.assign(n, vector<int>(n, 0)); // 각 도시로 가는 비용 0으로 초기화
    for (int i = 0; i < n; i++) { //비용 입력받아 matrix에 저장
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    //연산
    visited[0] = true;// 0번 도시 방문 -> visited 배열의 0번 인덱스 true로 변경
    backtracking(1, 0, 0);

    //출력
    cout << ans;
    return 0;
}
