#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int i, int j){
    return j <i;

};
int main(){
    int n,newScore,p,s;
    vector<int> scores;
    cin >>n>>newScore>>p;
    scores.assign(n,0);
    for(int i=0;i<n;i++){
        cin >>s;
        scores[i]=s;
    }
    sort(scores.begin(),scores.end(),cmp);
    if(scores.size()+1 > p){
        if(scores[scores.size()-1] < newScore){
            scores.push_back(newScore);
            sort(scores.begin(),scores.end(),cmp);
            cout <<find(scores.begin(),scores.end(),newScore)-scores.begin()+1;
        }
        else{
            cout << -1;
        }
    }
    else{
        scores.push_back(newScore);
        sort(scores.begin(),scores.end(),cmp);
        cout <<find(scores.begin(),scores.end(),newScore)-scores.begin()+1;
    }

    return 0;
}