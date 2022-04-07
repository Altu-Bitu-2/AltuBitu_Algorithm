#include <iostream>
#include <deque>

using namespace std;

string password(string l){
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
  string result;
    while(!left.empty()){
        result.push_back(left.front());
        left.pop_front();
    }
    while(!right.empty()){
        result.push_back((right.front()));
        right.pop_front();
    }

    return result;

}

int main(){
    int t;
    cin >> t;

    while(t--){
        string l;
        cin >>l;

        cout<<password(l)<<"\n";


    }
    return 0;
}
