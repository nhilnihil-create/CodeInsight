#include <bits/stdc++.h>
using namespace std;
constexpr long long MOD = 1000000007;
using ll = long long;
int main() {
ll a,b,c;
cin >> a >> b >> c;
if (a % 2 == 0 || b % 2 == 0 || c % 2 == 0) cout << "0" << endl;
else
    cout << min({a * b, b * c, c * a});
}
