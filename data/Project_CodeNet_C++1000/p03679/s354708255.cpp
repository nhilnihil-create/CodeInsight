#include <bits/stdc++.h>
using namespace std;
constexpr long long MOD = 1000000007;
using ll = long long;
int main() {
    ll x, a, b;
    cin >> x >> a >> b;
    if (b - a > x) cout << "dangerous" << endl;
    else if(b-a<=0)
        cout << "delicious" << endl;
    else
        cout << "safe" << endl;
}
