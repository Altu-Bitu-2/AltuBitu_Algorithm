#include <iostream>
#include <vector>

using namespace std;
long long minCost(vector<int> &roadL,vector<int> &oilP){
    long long result=0;
    int minP=oilP[0];
    for(int i=0;i<oilP.size()-1;i++){
        if(oilP[i]<minP){
            result+=roadL[i]*oilP[i];
            minP=oilP[i];
        }
        else{
            result+=roadL[i]*minP;
        }

    }
    return result;

}



int main(){
    int n;
    cin >> n;
    vector<int> roadL(n-1,0);
    vector<int> oilP(n,0);
    for(int i=0;i<n-1;i++){
        cin >>roadL[i];
    }
    for(int i=0;i<n;i++){
        cin >>oilP[i];
    }

    cout << minCost(roadL,oilP);

    return 0;
}
