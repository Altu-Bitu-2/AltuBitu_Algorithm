#include <iostream>
#include <queue>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    priority_queue<int,vector<int>,greater<int>> q;
    int n,num;
    cin >> n;
    for(int i=0;i<n*n;i++){
        cin >> num;
        if(q.size()<n){
            q.push(num);
        }
        else{
            if(q.top()<=num){
                q.push(num);
                q.pop();
            }
        }

    }
    cout <<q.top();

    return 0;

}