#include <iostream>


using namespace std;

int gcdRecursion(int a, int b) {

    if (b == 0) {
        return a;
    }
    return gcdRecursion(b, a % b);
}

int main() {
    string s;
    cin >> s;
    string a = s.substr(0, s.find(':'));
    string b = s.substr(s.find(':') + 1, s.length());
    int n1 = stoi(a);
    int n2 = stoi(b);

    int g = gcdRecursion(n1, n2);


    cout << n1 / g << ":" << n2 / g;

    return 0;


}