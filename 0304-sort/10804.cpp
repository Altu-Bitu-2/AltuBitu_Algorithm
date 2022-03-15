#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int SIZE = 20; //배열 크기 선언

vector<int> arr(SIZE + 1); //1번 인덱스부터 시작하기 위해 크기를 (SIZE + 1)로 선언

//a ~ b를 역순으로 배치하는 함수, reverse 함수 직접 구현
void reverseAtoB(int a, int b) {
    //더하고 빼는 변화값을 증가변수로 줘서 사용, 절반까지만
    for (int i = 0; i <= (b - a) / 2; i++) {
        swap(arr[a + i], arr[b - i]); //swap함수를 이용하여 배열 1번 인덱스부터 배열의 뒷부분과 서로 교환
    }
}

/**
 * 단순 구현 문제.
 * 1. 직접 구현: 카드를 역순으로 두기 = 수열을 반으로 접었다 생각할 때, 마주보는 원소끼리 swap!
 * 2. 함수 활용: <algorithm> 헤더에 있는 "reverse" 함수 사용 -> reverse(시작 반복자, 종료 반복자): 시작 ~ 종료전까지 원소들을 뒤집음
 */

int main() {
    int a, b; //입력받을 변수, 역순으로 놓을 함수의 인덱스 범위(a~b)

    //카드 초기화
    for (int i = 1; i <= SIZE; i++) {
        arr[i] = i; //인덱스 1번부터 1~20까지의 숫자 넣음
    }
    //입력 & 연산
    //입력이 10개로 한정되므로 for문으로 10번 입력받는 것도 가능!
    while (cin >> a >> b) { //입력이 있을 때까지만 받음 (입력이 끝나면 ctrl+D 를 눌러서 종료!)
        //헤더 함수 사용
        reverse(arr.begin() + a, arr.begin() + b + 1); //배열의 시작에서 a만큼 더한 인덱스부터 배열의 시작에서 b+1만큼 더한 인덱스까지(index a~index b) reverse함수를 이용하여 역순처리

        //직접 구현
        //reverseAtoB(a, b);
    }
    //출력
    for (int i = 1; i <= SIZE; i++) { //인덱스 1번부터 배열의 크기까지 for문 이용하여 출력
        cout << arr[i] << ' ';
    }
    return 0;
}