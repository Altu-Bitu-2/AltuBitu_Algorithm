#include <iostream>
#include <map>

using namespace std;


int main() {
    string s;
    int N;
    map<string, int> file;
    cin >> N;

    while(N--){
        cin >> s;
        int p;
        p=s.find(".");
        s.erase(0,p+1);
        file[s]++;

    }

   for(auto iter= file.begin();iter!=file.end();iter++){

        cout << iter->first<<" "<<iter->second<<"\n";

    }

    return 0;
}
