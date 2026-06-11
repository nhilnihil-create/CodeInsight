#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
#define MOD 1000000007
#define INF (1 << 30)
#define REP(i, m, n) for(int i = (int)m; i < (int)n; ++i)
#define rep(i, n) REP(i, 0, n)


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s; cin >> s;
    int N = s.size();
    string original = "CODEFESTIVAL2016";
    int ans = 0;
    rep(i, N) if(s[i] != original[i]) ans++;
    cout << ans << '\n';
    return 0;
}