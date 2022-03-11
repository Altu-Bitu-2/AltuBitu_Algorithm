#include <iostream>

using namespace std;

const int MINUTE = 60; //1분 초로 나타냄
const int HOUR = 60 * MINUTE; //1시간 초로 나타냄
const int DAY = 24 * HOUR; //하루 초로 나타냄

//변화하는 초 값 계산해서 보내주는 함수
int changeTime(int t, int c) {
    //돌리는 초가 하루보다 크다면 하루가 넘어가므로 모듈러 연산 후 연산
    int change_value = c % DAY;
    if (t == 2) { //시간 뒤로
        change_value = -change_value;//t가 2면
    }
    return change_value;
}

/**
 * 단순 구현 문제
 * 시계를 앞으로 돌리면 +, 뒤로 돌리면 -
 * !주의! 전날로 돌아가거나 다음날로 넘어갈 수 있으므로 항상 모듈러 연산을 하고,
 *       전날로 넘어갔을 경우 (음수값) 하루를 더해주는게 중요
 */

int main() {
    //입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int h, m, s, q, t, c, second = 0; //각각 시,분,초,쿼리 수,쿼리,돌릴 시간(초)
    //입력
    cin >> h >> m >> s; //현재 시간 시,분,초로 입력받음
    cin >> q; //쿼리개수 입력받음
    //시간 초기화
    second = h * HOUR + m * MINUTE + s; //시간을 초로 바꿈
    //입력 & 연산 & 출력
    while (q--) { //q가 0이 아닌 동안 (q가 1이상일 동안)
        cin >> t; //쿼리 입력 받음
        if (t == 3) { //시계가 가리키는 시간 출력
            second %= DAY; //하루가 넘어갔을 수 있으므로 모듈러 연산
            h = second / HOUR; //초를 시로
            m = (second % HOUR) / MINUTE; //초를 분으로
            s = (second % HOUR) % MINUTE; //전체 시간에서 시간과 분을 나눠 초 구함
            cout << h << ' ' << m << ' ' << s << '\n'; //시 분 초 출력
        } else { //t=1, 시계 앞으로(+) / t=2, 시계 뒤로(-)
            cin >> c; //돌릴 초 입력받음
            second += changeTime(t, c); //위에서 정의한 함수 수행행            if (second < 0) //전날로 넘어갔다면
                second += DAY; //하루 더해서 전날의 초(s) 양수로
        }
    }
    return 0;
}