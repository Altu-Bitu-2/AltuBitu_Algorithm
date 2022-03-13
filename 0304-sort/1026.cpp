#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//함수 S의 계산
int calcS(int n, vector<int> a, vector<int> b) {
    int s = 0; //함수의 결과 값을 저장할 변수 s를 0으로 초기화
    for (int i = 0; i < n; i++) { //a와 b배열의 크기만큼 for문을 이용하여 연산
        s += (a[i] * b[i]); //인덱스가 동일한 a배열과 b배열의 값을 곱한 수를 변수 s에 더해줌
    }
    return s; //최종적인 s값 반환
}

/**
 * 문제에서 B를 재배열하지 말라곤 했지만, 해야하는 문제
 * 각 배열에서 가장 큰 값과 가장 작은 값을 곱해야 최솟값이 나옴!
 */

int main() {
    int n; //배열의 크기 입력받을 변수
    vector<int> a, b; //벡터 a,b 선언

    //입력
    cin >> n; //배열 크기 입력 받음
    a.assign(n, 0); //벡터 a에 n만큼의 크기를 할당하고 0으로 초기화
    b.assign(n, 0);//벡터 b에 n만큼의 크기를 할당하고 0으로 초기화
    for (int i = 0; i < n; i++) {
        cin >> a[i]; //벡터의 인덱스 0부터 n-1까지 저장할 값을 입력받음
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];//벡터의 인덱스 0부터 n-1까지 저장할 값을 입력받음
    }

    //연산
    sort(a.begin(), a.end()); //오름차순 정렬
    sort(b.begin(), b.end(), greater<>()); //내림차순 정렬
    int result = calcS(n, a, b); //위에서 정의한 calcS함수로 결과값 계산

    //출력
    cout << result;
    return 0;
}
