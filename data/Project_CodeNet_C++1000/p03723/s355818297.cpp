#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if(a % 2 != 0 || b % 2 != 0 || c % 2 != 0) cout << 0 << endl;
    else if(a == b && b == c) cout << -1 << endl;
    else {
        int ans = 0;
        while(a % 2 == 0 && b % 2 == 0 && c % 2 == 0) {
            int d = (b + c) / 2;
            int e = (a + c) / 2;
            int f = (a + b) / 2;
            a = d;
            b = e;
            c = f;
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}