#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;

int x[8];

int main()
{
    int n;
    cin >> n;
    int tourist = 0;
    rep(i, n) {
        int a;
        cin >> a;
        if(a < 400) x[0]++;
        else if(a < 800) x[1]++;
        else if(a < 1200) x[2]++;
        else if(a < 1600) x[3]++;
        else if(a < 2000) x[4]++;
        else if(a < 2400) x[5]++;
        else if(a < 2800) x[6]++;
        else if(a < 3200) x[7]++;
        else tourist++;
    }
    int ans = 0;
    rep(i, 8) {
        if(x[i] != 0) ans++;
    }
    if(tourist == 0) cout << ans << " " << ans << endl;
    else {
        cout << max(ans, 1) << " " << ans + tourist << endl;
    }
    return 0;
}
