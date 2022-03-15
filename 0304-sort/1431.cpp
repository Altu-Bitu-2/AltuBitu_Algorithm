#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//문자열의 모든 자릿수 합을 구하는 함수
int sumNum(string str) {
    int sum = 0; //문자열의 모든 자릿수 합을 저장할 변수 sum 0으로 초기화
    for (int i = 0; i < str.size(); i++) {
        if (isdigit(str[i])) { //문자(char)에 대해 숫자인지 판별하는 함수
            sum += str[i] - '0'; //char -> int로 바꾸는 방법 (아스키 코드에 대해 알아보세요)
        }
    }
    return sum; //결과값 sum반환
}

//비교함수
bool cmp(const string &s1, const string &s2) {
    if (s1.size() != s2.size()) { //두 문자열의 길이가 다르다면 짧은 문자열이 먼저 오도록
        return s1.size() < s2.size(); //s1의 문자열이 s2보다 짧다면 true , 아니면 false
    }
    if (sumNum(s1) != sumNum(s2)) { //두 문자열의 숫자 합이 다르다면 합이 작은 문자열이 먼저 오도록
        return sumNum(s1) < sumNum(s2);//s1의 문자열의 숫자합이 s2보다 작다면 true , 아니면 false
    }
    return s1 < s2; //사전순, 위의 두 경우에 모두 해당되지 않는다면 사전 순, s1이 이전이면 true, 아니면 false
}

int main() {
    int n; //기타의 개수를 입력받을 변수 n 선언
    vector<string> serial_num; //기타의 시리얼 번호를 저장할 벡터 serial_num선언

    //입력
    cin >> n; //기타의 개수 입력받아 n에 저장
    serial_num.assign(n, ""); //serial_num벡터에 n만큼의 크기를 할당하고 빈문자열로 초기화
    for (int i = 0; i < n; i++) {
        cin >> serial_num[i]; //기타의 개수만큼 serial_num에 문자열 저장
    }

    //연산
    sort(serial_num.begin(), serial_num.end(), cmp); //sort함수를 이용하여 serial_num을 위에서 선언한 cmp함수의 방식으로 정렬

    //출력
    for (int i = 0; i < n; i++) {
        cout << serial_num[i] << '\n'; //정렬이 완료된 serial_num 출력
    }
    return 0;
}
