#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> ci; //순서상 ci선언

bool cmp(const ci &a, const ci &b) {
    if (a.second != b.second) { //1. y좌표가 증가하는 순서
        return a.second < b.second; // y좌표가 같지 않을 경우, a의 y좌표가 작으면 true, 아니면 false
    }
    return a.first < b.first; //2. (y좌표가 같으면) x좌표가 증가하는 순서
}

int main() {
    int n, a, b; //점의 개수를 저장할 변수 n

    //입력
    cin >> n; //점의 개수 입력받음
    vector<ci> arr(n, {0, 0}); //vector arr에 n만큼 크기 할당해주고 (0,0)으로 초기화
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second; //벡터의 크기만큼 점 좌표 입력받아 저장
    }
    //연산
    sort(arr.begin(), arr.end(), cmp);//sort함수를 이용하여 arr의 원소들을 위에서 선언한 cmp함수의 방식으로 정렬
    //출력
    for (int i = 0; i < n; i++) {
        cout << arr[i].first << ' ' << arr[i].second << '\n'; //정렬이 완료된 점의 좌표들 출력
    }
    return 0;
}
