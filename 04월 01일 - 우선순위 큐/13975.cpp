#include <iostream>
#include <queue>

using namespace std;


int minCost(priority_queue<int,vector<int>, greater<int>> &q){
    int result =0;
    while(true){
        int sum=0;
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
    priority_queue<int,vector<int>, greater<int>> q;
    cin >> t;
    while(t--){
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