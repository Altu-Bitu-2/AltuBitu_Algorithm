#include <iostream>
#include <set>
#include <vector>

using namespace std;

int compareNum(int n, vector<int> &note2,set<int> &note1){
    for(int i=0; i<n ;i++){
        for(auto iter=note1.begin();iter!=note1.end();iter++){
            if(*iter == note2[i]){
                cout << "1"<<"\n";
                break;
            }
            if(*iter == *note1.end()){
                cout <<"0"<<"\n";
            }
        }
    }

}


int main (){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;


    while(T--){

        int N,M,input;
        set <int> note1;

        cin >> N;
        for(int i=0;i<N;i++){
            cin >> input;
            note1.insert(input);
        }

        cin >> M;
        vector <int> note2(M);
        for(int i=0;i<M;i++){
            cin >> note2[i];
        }
        compareNum(M,note2,note1);

    }

    return 0;

}
