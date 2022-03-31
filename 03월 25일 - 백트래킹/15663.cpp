#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n,m,num;
    vector<int> v;
    cin >>n>>m;

    v.assign(n,0);
    for(int i=0;i<n;i++){
        cin >>num;
        v[i]=num;
    }

    sort(v.begin(),v.end());
    do{
        for(int i=0;i<m;i++){
            cout <<v[i]<<" ";
        }
        cout <<endl;
        reverse(v.begin()+m,v.end());

    }while(next_permutation(v.begin(),v.end()));


return 0;
}
