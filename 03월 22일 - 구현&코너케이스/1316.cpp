#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    int n;
    string a;
    int v[27];
    bool isGroup =true;
    int result=0;

    for(int i=0;i<27;i++){
        v[i]=0;
    }

    cin >> n;

    while (n--) {
        cin >>a;
        v[a[0]-'a']++;
        for (int i = 1; i < a.length(); i++) {
            if(a[i-1]!=a[i] && v[a[i]-'a'] == 1){
                isGroup =false;
                break;
            }
           else if(a[i-1]!=a[i] && v[a[i]-'a']!=1){
               v[a[i]-'a']=1;
           }
        }
        if(isGroup){
            result++;
        }

    }

    cout <<result;

    return 0;
}