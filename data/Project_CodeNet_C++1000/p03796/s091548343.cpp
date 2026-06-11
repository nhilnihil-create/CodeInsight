#include <iostream>
using namespace std;

const int MOD = 1000000007;
int n;
long long int power = 1;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        power = ((power % MOD) * i) % MOD;
    }

    cout << power << endl;

    return 0;
}