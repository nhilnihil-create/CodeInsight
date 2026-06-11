#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    string ans = "No";
    rep(i, n+1) {
        rep(j, m+1) {
            if(i*(m-j)+j*(n-i)==k) {
                ans = "Yes";
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
