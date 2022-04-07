#include <iostream>
#include <queue>

using namespace std;


long long minCost(priority_queue<int,vector<int>, greater<int>> &q){
    long long result =0;
    while(true){
        long long sum=0;
        sum+=q.top();
        q.pop();
        sum+=q.top();
        q.pop();
        result+=sum;
        q.push(sum);

        if(q.size()==1){
            break;
        }
    }
    return result;
}

int main(){
    int t,k;
    cin >> t;
    while(t--){
        priority_queue<int,vector<int>, greater<int>> q;
        cin >>k;
        while(k--){
            int tmp;
            cin >> tmp;
            q.push(tmp);
        }
        cout <<minCost(q)<<"\n";
    }

    return 0;
}