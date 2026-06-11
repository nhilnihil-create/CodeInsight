#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define dbg(x) cerr << #x << " = " << x << endl
#define _ << ' ' <<
using namespace std;
using ll = long long;
using vi = vector<int>;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll s, c;
    cin >> s >> c;
    ll k = min(s, c / 2);
    s -= k;
    c -= 2 * k;
    cout << k + c / 4;
}
