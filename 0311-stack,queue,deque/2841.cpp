#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/**
 * 각 줄마다 외계인이 누르고 있는 프렛을 스택에 저장하기
 * 매 입력에 대해 이번에 누를 프렛이 해당 줄에서 가장 높은 프렛이어야 함
 *
 * 1. 이번에 눌러야 할 프렛보다 높은 프렛에서 손가락을 전부 떼기
 * 2. 만약 이번에 눌러야 할 프렛을 누르고 있지 않다면 누르기
 *
 * 존재하지 않는 0번 프렛을 활용해서 스택에 미리 넣어줌으로써 매번 empty 체크를 해야 하는 연산을 줄임
 */
int main() {
    int n, p, guitar_string, fret, ans = 0; //음의 수 입력받을 n, 프렛의 수 입력 받을 p, 줄의 번호 입력받을 guitar_string,프렛의 번호 입력받을 fret, 최종 답 입력받을 ans

    cin >> n >> p;//음의 수와 프렛의 수 입력받음
    vector<stack<int>> guitar(7); //1번 줄부터 6번줄 까지
    for (int i = 1; i <= 6; i++) { //스택에 미리 0을 넣어서 매번 empty 체크를 하는 연산을 줄임
        guitar[i].push(0);
    }
    while (n--) { //입력받은 음의 수 만큼 반복
        //입력
        cin >> guitar_string >> fret; //줄의 번호와 프렛의 번호 입력 받음

        //연산
        while (guitar[guitar_string].top() > fret) { //프렛에서 손가락 떼기, 입력받은 프렛의 번호가 입력받은 줄의 top값 보다 작다면
            ans++; //손 움직임 1 추가
            guitar[guitar_string].pop(); // 해당 줄의 top값 pop
        }
        if (guitar[guitar_string].top() != fret) { //프렛 누르기
            ans++; //손 움직임 1 추가
            guitar[guitar_string].push(fret); //해당 줄에 해당하는 인덱스에 입력한 fret값 push
        }
    }

    //출력
    cout << ans;
}