#include <iostream>
#include <vector>

using namespace std;

vector<char> password(string l){
    vector <char> str(l.size(),' ');
    int cursor =0;
    for(int i=0;i<l.length();i++){
        switch(l[i]){
            case '<':
                if(cursor>0){
                    cursor--;
                }
                break;
            case '>':
                if(cursor+1 < str.size()){
                    cursor++;
                }
                break;
            case '-':
                if(cursor>0){
                    str.erase(str.begin()+cursor-1);
                    cursor--;
                }
                break;
            default:
                str.insert(str.begin()+cursor,l[i]);
                cursor++;

        }
    }

    return str;

}

int main(){
    int t;
    cin >> t;

    while(t--){
        string l;
        cin >>l;
        vector<char> result =password(l);

        for(int i=0;i<result.size();i++){
            if(result[i] !=' '){
                cout <<result[i];
            }

        }
        cout<<"\n";


    }
    return 0;
}
