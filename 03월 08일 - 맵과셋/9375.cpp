#include <iostream>
#include <map>
#include <set>

using namespace std;



int main(){
    int T,n;
    string c,t;
    cin >> T;


    while(T--){
        int result=1;
        map <string,int>m;
        set<string> s;
        cin >>n;
        for(int i=0;i<n;i++){
            cin >>c;
            cin >>t;
            if(s.find(t) !=s.end()){
                m[t]++;
            }
            else{
                s.insert(t);
                m[t]++;
            }
        }

        for(auto iter=m.begin();iter!=m.end();iter++){
            result*=(iter->second+1);
        }
        result-=1;
        cout << result<<"\n";

    }

    return 0;

}