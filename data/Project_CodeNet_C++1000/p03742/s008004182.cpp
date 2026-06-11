#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    ll x, y;
    cin >> x >> y;
    if (abs(x - y) <= 1) cout << "Brown\n";
    else cout << "Alice\n";
}
