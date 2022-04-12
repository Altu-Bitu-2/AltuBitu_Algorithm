#include <iostream>
#include <vector>

using namespace std;

//부분 행렬 원소 뒤집는 함수
void reverseMtx(int row, int col, vector<string> &matrix_a) {
    for (int i = row; i < row + 3; i++) { //row에서 row+2까지 반복문
        for (int j = col; j < col + 3; j++) { //col에서 col+2까지 반복문
            if (matrix_a[i][j] == '1') { //1이면 0으로 reverse
                matrix_a[i][j] = '0';
            }
            else {//0이면 1로 reverse
                matrix_a[i][j] = '1';
            }
        }
    }
}

//마지막으로 A == B인지 확인하는 함수
int isPossible(int n, int m, vector<string> &matrix_a, vector<string> &matrix_b) {
    for (int i = 0; i < n; i++) { //매트릭스의 크기만큼 반복문
        for (int j = 0; j < m; j++) {
            if (matrix_a[i][j] != matrix_b[i][j]) {  //두개의 매트릭스의 원소가 다르다면 return false
                return false;
            }
        }
    }
    return true; //반복문을 다 돌고 나왔다면 return true
}

/**
 * [행렬]
 *
 * (0, 0) 인덱스부터 부분행렬을 만들 수 있는 마지막 인덱스까지 검사하며 그리디하게 푸는 문제
 * A, B 행렬의 현재 인덱스 값이 서로 다르다면 A 행렬에서 현재 인덱스로 '시작'하는 3x3 크기만큼의 부분 행렬 원소 뒤집기
 * 검사가 모두 끝난 후, A와 B가 서로 다르다면 바꿀 수 없는 경우임
 * !주의! 입력이 공백없이 주어지므로 string으로 받음
 */

int main() {
    int n, m;

    //입력
    cin >> n >> m;
    vector<string> matrix_a(n); //첫번째 matrix
    vector<string> matrix_b(n); //두번째 matrix
    for (int i = 0; i < n; i++) { //첫번째 matrix 입력받기
        cin >> matrix_a[i];
    }

    for (int i = 0; i < n; i++) {//두번째 matrix 입력받기기
       cin >> matrix_b[i];
    }

    //연산
    int ans = 0; //연산횟수 저장 변수
    for (int i = 0; i <= n - 3; i++) {
        for (int j = 0; j <= m - 3; j++) {
            if (matrix_a[i][j] != matrix_b[i][j]) { //(i, j)원소가 서로 다르다면
                reverseMtx(i, j, matrix_a); //reverse 연산 수행
                ans++; //연산횟수 +1
            }
        }
    }

    //출력
    if (!isPossible(n, m, matrix_a, matrix_b)) { //연산이 모두 끝난 후 두 매트릭스가 같은지 확인
        ans = -1; //같지 않다면 ans에 -1 저장
    }
    cout << ans; //ans 출력력    return 0;
}