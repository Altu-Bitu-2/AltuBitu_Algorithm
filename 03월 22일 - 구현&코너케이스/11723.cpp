#include <iostream>
#include <vector>
#include <string>

using namespace std;
const int SIZE = 21;

/**
 * [집합] - 단순 구현 문제
 *
 * ver1. 배열 사용 풀이
 * set()을 사용해서 매번 연산을 하면 시간이 굉장히 오래 걸려요.
 * 입력되는 x의 값이 1~20으로 범위가 매우 작기 때문에, 각 숫자가 집합에 들어있는 여부를 저장하는 배열을 이용합니다.
 *
 * 1. 집합에는 1~20의 숫자만 입력 or 제거됨 (=true or false)
 * 2. 크기 21의 bool 배열을 선언
 * 3. 입력은 true 처리, 제거는 false 처리
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int m, num; //수행할 연산의 수,
    string cmd; //수행할 연산
    vector<bool> s(SIZE, false);

    cin >> m; //수행할 연산의 수 입력받기
    while (m--) { //입력받은 연산의 수만큼 반복
        cin >> cmd; //수행할 연산 입력받기
        if (cmd == "all") { //all을 입력받았을 경우
            s.assign(SIZE, true); //벡터에 SIZE만큼 크기를 할당하고 true로 초기화
            continue; //반복문 계속
        }
        if (cmd == "empty") { //empty를 입력받았을 경우
            s.assign(SIZE, false);//벡터에 SIZE만큼 크기를 할당하고 false로 초기화
            continue;//반복문 계속
        }

        cin >> num; // x입력 받기
        if (cmd == "add") { //add를 입력받았을 경우
            s[num] = true; //s의 x인덱스 위치에 있는 값 true로 변경
            continue;//반복문 계속
        }
        if (cmd == "remove") {//remove를 입력받았을 경우
            s[num] = false;//s의 x인덱스 위치에 있는 값 false로 변경
            continue;//반복문 계속
        }
        if (cmd == "check") { //check를 입력받았을 경우
            cout << s[num] << '\n'; //bool 형을 출력하면 true: 1, false: 0으로 출력
            continue; //반복문 계속
        }
        if (cmd == "toggle") {//toggle을 입력받았을 경우
            s[num] = !s[num]; //true ->false로 false->true로 변경
            continue;//반복문 계속
        }
    }
    return 0;
}