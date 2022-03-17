#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main(){
    int K,N,tmp;
    cin >>N >>K;
    deque<int> d;
    vector<int> v;

    v.assign(N,0);

    for(int i=1;i<=N;i++){
        d.push_back(i);
    }
    cout <<"<";
    while(N--){
        for(int i=0;i<K;i++){
            tmp=d.front();
            d.pop_front();
            d.push_back(tmp);
        }
        d.pop_back();
        if(N>0){
            cout<<tmp<<", ";
        }
        else{
            cout<<tmp;
        }


    }
    cout<<">"<<endl;

    return 0;

}

