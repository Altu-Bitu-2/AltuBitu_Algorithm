#include <iostream>
#include <set>

using namespace std;


int main(){
    int t,k,n;
    char c;
    cin >>t;
    while(t--){
        cin >>k;
        multiset<int> q;
        while(k--){
            cin >>c>>n;
            if(c== 'I'){
                q.insert(n);
            }
            if(c=='D'){
                if(q.empty()){
                    continue;
                }
                if(n==1){
                    q.erase(--q.end());
                }
                if(n==-1){
                    q.erase(q.begin());
                }

            }

        }

        if(q.empty()){
            cout << "EMPTY"<<"\n";
        }
        else{
            auto iter = q.begin();
            auto iter2 =q.end();
            cout << *(--iter2) <<" "<<*iter<<"\n";
        }


    }

    return 0;
}