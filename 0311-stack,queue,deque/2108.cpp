#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    if(a.second!=b.second){
        return a.second > b.second;
    }
    else{
        return a.first>b.first;
    }

}


//산술평균
int calcMean(vector<int> v){
    double sum=0;

    for(int i=0;i<v.size();i++){
        sum+=v[i];
    }
    double mean =sum/v.size();

    if(round(mean)==-0){
        return -round(mean);
    }
    else{
        return round(mean);
    }

}

//중앙값
int calcMedian(vector<int> v){
    sort(v.begin(),v.end());
    return v[v.size()/2];
}

//최빈값
int calcMode(vector<int> v){
    map<int,int> m;
    set<int>s;
    int maxTimes=0;

    for(int i= 0; i<v.size();i++){
        int n = v[i];
        m[n]++;
    }
    vector<pair<int,int>> k {m.begin(),m.end()};
    sort(k.begin(),k.end(),cmp);
    for(int i=1;i<k.size();i++){
        if(k[0].second == k[i].second){
            maxTimes++;
        }
    }
    if(maxTimes==0){
        return k[0].first;
    }
    else{
        return k[maxTimes-1].first;
    }

}

//범위
int calcRange(vector<int> v){
    sort(v.begin(),v.end());
    int min=v[0];
    int max=v[v.size()-1];
    int range =max-min;
    return range;
}

int main(){
    int N;
    vector<int> v;

    cin >>N;
    v.assign(N,0);
    for(int i=0;i<N;i++){
        cin >>v[i];

    }

    cout << calcMean(v)<<"\n";
    cout << calcMedian(v)<<"\n";
    cout << calcMode(v)<<"\n";
    cout << calcRange(v);


    return 0;
}
