#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;


int requiredMileage(int p,int l,vector<int> &q){
    sort(q.begin(),q.end());
  if(p<l){
      return 1;
  }
  else{
      return q[q.size()-l];
  }
}

int main(){
    int n,m,p,l;
    int result=0;
    int sum=0;
    priority_queue<int,vector<int>, greater<int>> q;
    cin >>n >>m;

    while(n--){
        cin >>p>>l;
        vector<int> mil(p,0);
        for(int i=0;i<p;i++){
            cin >>mil[i];
        }
        q.push(requiredMileage(p,l,mil));
    }

    while(!q.empty()){

            sum+=q.top();
            result++;
            q.pop();

        if(sum>m){
            result--;
            break;
        }

    }

    cout <<result;
    return 0;
}