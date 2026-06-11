#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;

int main()
{
    ll n, a, b;
    cin >> n >> a >> b;
    if(a > b) cout << 0 << endl;
    else if(n == 1) {
        if(a == b) cout << 1 << endl;
        else cout << 0 << endl;
    }
    else cout << a + (n - 1) * b - (n - 1) * a - b + 1<< endl;
    return 0;
}