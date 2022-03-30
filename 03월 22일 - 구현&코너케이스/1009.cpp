#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;
    int a, b;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        a %= 10;
        b %= 4;
        if(b==0){
            b=4;
        }
        if(a==0){
            cout <<10<<"\n";
        }
        else{
            int tmp = pow(a,b);
            cout <<tmp%10<<"\n";
        }


    }

    return 0;
}