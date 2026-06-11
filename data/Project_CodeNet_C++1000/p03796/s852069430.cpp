#include <iostream>
using namespace std;


int main() {
    long n, power = 1;
    const int mod = 1000000007;
    cin >> n;

    for (long i = 1; i < n+1; ++i) {
        power = power % mod * i % mod;
    }

    cout << power << endl;
}
