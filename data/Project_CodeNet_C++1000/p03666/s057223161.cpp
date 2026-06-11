#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ll n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;

    for(int j = 0; j < n; j++) {
        ll u = a + (n-1-j)*c - j*d;
        ll v = a - j*c + (n-1-j)*d;
        if(u <= b && b <= v) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    return 0;
}