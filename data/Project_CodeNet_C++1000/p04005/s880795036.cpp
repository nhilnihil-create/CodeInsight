#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

const int MOD = (int) 1e9 + 7;

int main()
{
    ll a, b, c;
    cin >> a >> b >> c;
    if(a % 2 == 0 || b % 2 == 0 || c % 2 == 0) cout << 0 << endl;
    else {
        if(a >= b && a >= c) {
            cout << c * b << endl;
        }
        else if(b >= c) cout << a * c << endl;
        else cout << a * b << endl;
    }
    return 0;
}
