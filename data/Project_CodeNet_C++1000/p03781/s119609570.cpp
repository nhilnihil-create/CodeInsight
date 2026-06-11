#include <iostream>
#include <cmath>

typedef long long ll;

using namespace std;

int main() {
    ll x;
    cin >> x;
    ll n = ceil((sqrt(1 + 8 * x) - 1) / 2);
    cout << n << endl;
    return 0;
}
