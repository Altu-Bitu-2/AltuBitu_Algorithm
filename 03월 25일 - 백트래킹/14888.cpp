#include <iostream>
#include <vector>

using namespace std;
const int INF_MAX = 1e9;
const int SIZE = 11;

int n; //수의 개수 입력 받을 변수
vector<int> num(SIZE + 1); //연산할 수 입력 받을 벡터
vector<int> expression(4); //0: +, 1: -, 2: *, 3: /
int max_value = -INF_MAX, min_value = INF_MAX; //연산 결과의 최댓값, 최솟값을 최댓값으로 초기화 해둠

void backtracking(int cnt, int sum) { //cnt: 수 인덱스, sum: 연산 결과
    if (cnt == n - 1) { //연산 모두 완료했다면 (기저조건)
        max_value = max(max_value, sum); //새로 연산한 결과와 이전 결과 값을 비교하여 큰 값 max_value에 저장
        min_value = min(min_value, sum);//새로 연산한 결과와 이전 결과 값을 비교하여 작은 값 max_value에 저장
        return;
    }
    for (int i = 0; i < 4; i++) { //연산자 검사
        if (expression[i]) { //해당 연산자의 연산 횟수가 0이 아닐 경우
            expression[i]--; //해상 연산자의 연산횟수-1
            int new_sum = 0; //연산 결과 저장할 변수
            switch (i) { //연산자 종류에 따라
                case 0: //expression의 0번 index는 덧셈연산
                    new_sum = sum + num[cnt + 1];
                    break;
                case 1://expression의 1번 index는 뺄셈연산
                    new_sum = sum - num[cnt + 1];
                    break;
                case 2://expression의 2번 index는 곱셈연산
                    new_sum = sum * num[cnt + 1];
                    break;
                case 3://expression의 3번 index는 나눗셈연산
                    new_sum = sum / num[cnt + 1];
                    break;
            }
            backtracking(cnt + 1, new_sum); //다음 연산 백트래킹으로 수행
            expression[i]++; //연산 마친 후 다시 원상태로 복귀
        }
    }
}

/**
 * 연산자 모두 돌려보면서 배치한 후, 각 연산자에 따른 값 계산
 */

int main() {
    //입력
    cin >> n; //연산할 숫자의 갯수 입력받음
    for (int i = 0; i < n; i++) { //n개만큼 숫자 입력받음
        cin >> num[i]; //num 벡터에 저장
    }
    for (int i = 0; i < 4; i++) { //사용할 연산자의 갯수 입력받음
        cin >> expression[i];// expression 벡터에 저장
    }

    //연산
    backtracking(0, num[0]);

    //출력
    cout << max_value << '\n' << min_value;
    return 0;
}