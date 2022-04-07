#include <iostream>
#include <deque>

using namespace std;

deque<char> password(string l){
    deque <char> left;
    deque <char> right;
    for(int i=0;i<l.length();i++){
        switch(l[i]){
            case '<':
                if(left.size()>0){
                    int tmp =left.back();
                    left.pop_back();
                    right.push_front(tmp);
                }
                break;
            case '>':
                if(right.size()>0){
                    int tmp =right.front();
                    right.pop_front();
                    left.push_back(tmp);
                }
                break;
            case '-':
                if(left.size()>0){
                    left.pop_back();
                }
                break;
            default:
                left.push_back(l[i]);
        }
    }
    while(!right.empty()){
        left.push_back(right.front());
    }

    return left;

}

int main(){
    int t;
    cin >> t;

    while(t--){
        string l;
        cin >>l;
        deque<char> result =password(l);

while(!result.empty()){
    cout <<result.front();
    result.pop_front();
}
        cout<<"\n";


    }
    return 0;
}
