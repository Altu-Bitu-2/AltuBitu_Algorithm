#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> calcMultiple(vector<int> &v){
    int sum=0;

    for(int i=0;i<v.size();i++){
      sum+=v[i];
    }
    sort(v.begin(),v.end());
    if(sum%3==0 && v[0]==0){
        return v;

    }
    else{
        while(!v.empty()){
            v.pop_back();
        }
        v.push_back(-1);
        return v;
    }

}

int main() {
    string n;
    vector<int> v;
    cin >> n;

    v.assign(n.length(),0);
    for (int i = 0; i < n.length(); i++) {
        v[i] = n[i]-'0';
    }

    calcMultiple(v);

    for (int i = v.size()-1; i >=0; i--){
        cout << v[i];
    }

    return 0;
}
