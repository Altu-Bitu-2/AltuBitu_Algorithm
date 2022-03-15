#include <iostream>
#include <set>

using namespace std;

int main (){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while(T--){

        int N,M,input1,input2;
        set <int> note;

        cin >> N;
        for(int i=0;i<N;i++){
            cin >> input1;
            note.insert(input1);
        }

        cin >> M;

        for(int i=0;i<M;i++){
            cin >> input2;
            if(note.find(input2)!=note.end()){
                cout << "1"<<"\n";
            }
            else{
                cout << "0"<<"\n";
            }
        }

    }

    return 0;

}
