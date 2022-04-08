#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n,a;
    priority_queue<int> p;
    cin >> n;

    while(n--){
        cin >> a;
        if(a ==0){
            if(p.empty()){
                cout <<-1<<"\n";
            }
            else{
                cout <<p.top()<<"\n";
                p.pop();
            }
        }
        else{
            while(a--){
                int tmp;
                cin >>tmp;
                p.push(tmp);
            }
        }

    }

    return 0;
}