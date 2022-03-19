#include <iostream>
#include <vector>
#include <stack>
#include <map>

using namespace std;

int calc(string s) {
    stack<char> st; //괄호쌍 저장할 스택
    map<char, int> num; //괄호 값
    map<char, char> bracket; //괄호 쌍

    //괄호 쌍과 값 저장
    bracket[')'] = '('; //( 와 ) 는 한쌍
    bracket[']'] = '['; //[ 와 ] 는 한쌍
    num['('] = 2; //() 쌍 값은 2
    num['['] = 3;//[] 쌍 값은 3

    int ans = 0, temp = 1; //최종 결과값 저장할 ans , 중간 결과값 저장할 temp
    for (int i = 0; i < s.length(); i++) { //문자열의 길이만큼 반복
        switch (s[i]) {
            case '(': case '[': //여는 괄호일 경우
                st.push(s[i]); //스택에 괄호 push
                temp *= num[s[i]]; // temp에 해당 괄호 값을 곱해줌
                break;
            case ')': case ']': //닫는 괄호일 경우
                if (st.empty() || st.top() != bracket[s[i]]) { //스택이 비어있거나(쌍이 되는 여는 괄호가 없거나) 괄호 쌍이 안맞을 경우
                    return 0; //잘못된 괄호쌍이므로 종료
                }
                if (s[i - 1] == bracket[s[i]]) { //스택에 저장되어있는 바로 직전의 괄호와 닫는 괄호의 쌍이 되는 여는 괄호가 동일한 경우(괄호가 닫힘)
                    ans += temp; //temp에 저장해둔 값을 ans에 저장
                }
                temp /= num[bracket[s[i]]]; //이미 값을 더한 경우이므로 나누기
                st.pop(); //괄호 비우기
                break;
        }
    }
    if (st.empty()) { //올바른 괄호라면,
        return ans; //최종 결과값 리턴
    }
    return 0;
}

/*
 * "분배법칙"을 활용!
 * ex. ([]([])): 2 x (3 + 2 x 3) == 2 x 3 + 2 x 2 x 3
 * =>                               (   [ ]     (   [   ]   )   )
 * =>                   임시변수값:  2   6 2     4  12   4   2   1
 * =>                        정답:        +6           +12        = 18
 *
 * 따라서, 우선 여는 괄호가 나오면 괄호의 값을 곱해줌
 * 닫는 괄호는, 이전 문자가 여는 괄호일 경우 지금까지 곱한 값을 더해줌 (값이 중복으로 더해지는 것을 방지하기 위해 이전 문자가 여는 괄호인지 꼭 체크!)
 *            한 괄호에 대한 연산이 끝났으므로 (곱하기 연산) 다시 괄호 값을 나눠줘서 연산 진행
 */

int main() {
    string s;

    //입력
    cin >> s;
    //연산 & 출력
    cout << calc(s);
    return 0;
}