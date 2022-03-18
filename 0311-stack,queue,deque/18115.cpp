#include<iostream>
#include<stack>
#include<deque>

using namespace std;

int main() {
    int N, a;
    stack<int> preCard, skill;
    deque<int> card, containCard;

    cin >> N;
    for (int i = N; i >= 1; i--) {
        preCard.push(i);
    }

    while (N--) {
        cin >> a;
        skill.push(a);
    }

    while(!skill.empty()){
        if (skill.top() == 1) {
            card.push_back(preCard.top());
            preCard.pop();
            skill.pop();
        }
        else if (skill.top() == 2) {
            int tmp = card.back();
            card.pop_back();
            card.push_back(preCard.top());
            card.push_back(tmp);
            preCard.pop();
            skill.pop();
        }
        else{
            card.push_front(preCard.top());
            preCard.pop();
            skill.pop();
        }

    }

    while(!card.empty()){
        cout << card.back() << " ";
        card.pop_back();
    }

    return 0;
}