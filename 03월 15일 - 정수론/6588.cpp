#include <iostream>
#include <vector>

using namespace std;
const int MAX = 10e6;


vector<int> findPrime() {
    vector<int> prime(MAX + 1, 0);
    for (int i = 2; i * i <= MAX; i++) {
        if (prime[i] != 0) {
            continue;
        }
        for (int j = i * i; j <= MAX; j += i) {
            if (prime[j] == 0) {
                prime[j] = i;
            }
        }
    }
    return prime;
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int a, b = 0;

    auto prime = findPrime();
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }
        for (int i = 2; i < prime.size(); i++) {
            if (prime[i] == 0) {
                a = i;
                b = n - a;
            }
            if (prime[b] == 0) {
                break;
            }
        }

        if (prime[b] != 0) {
            cout << "Goldbach's conjecture is wrong." << "\n";
        } else {
            cout << n << " = " << a << " + " << b << "\n";
        }


    }

    return 0;
}