#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
using namespace std;

//산술평균
void calcMean(vector<int> v){
    double sum=0;

    for(int i=0;i<v.size();i++){
        sum+=v[i];
    }
    double mean =sum/v.size();

    if(round(mean)==-0){
        cout <<-round(mean)<<"\n";
    }
    else{
        cout <<round(mean)<<"\n";
    }

}

//중앙값
void calcMedian(vector<int> v){
    multiset<int> ms;
    for(int i=0;i<v.size();i++){
        ms.insert(v[i]);
    }

    while(ms.size()!=1){
        ms.erase(--ms.end());
        ms.erase(ms.begin()--);
    }

    cout << * ms.begin()<<"\n";

}

//최빈값
void calcMode(vector<int> v){
    map<int,int> m;
    set<int>s,tmp;
    int max=1;
    int maxKey;

    for(int i= 0; i<v.size();i++){
        int n = v[i];
        m[n]++;
    }
    for(auto iter =m.begin();iter !=m.end();iter++){
        if(max <= iter->second){
            max = iter->second;
            maxKey = iter->first;
        }
    }
    for(auto iter =m.begin();iter !=m.end();iter++){
         tmp.insert(iter->second);
    }
    if(tmp.size()==1 && m.size() != 1){
        for(int i=0;i<v.size();i++){
            s.insert(v[i]);
        }
        s.erase(s.begin());
        cout<< * s.begin()<<"\n";

    }
    else{
        cout << maxKey<<"\n";
    }


}

//범위
void calcRange(vector<int> v){
    set<int> s;
    for(int i=0;i<v.size();i++){
        s.insert(v[i]);
    }
    auto max = s.rbegin();
    auto min =s.begin();
    int range =(*max)-(*min);

    cout<<range<<"\n";
}

int main(){
    int N;
    vector<int> v;

    cin >>N;
    v.assign(N,0);
    for(int i=0;i<N;i++){
        cin >>v[i];

    }

    calcMean(v);
    calcMedian(v);
    calcMode(v);
    calcRange(v);


    return 0;
}
