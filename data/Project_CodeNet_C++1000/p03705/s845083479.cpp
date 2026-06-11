#include<iostream>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    ll n, a, b;
    cin >> n >> a >> b;

    if (a > b || (n == 1 && a < b)) {
        cout << 0 << endl;
        return 0;
    }

    if (a == b) {
        cout << 1 << endl;
        return 0;
    }

    ll ans = (n - 2) * b - (n-2) * a + 1;
    cout << ans << endl;
}