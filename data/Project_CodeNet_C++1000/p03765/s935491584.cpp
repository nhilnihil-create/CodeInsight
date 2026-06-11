#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;

int sa[100010], sb[100010], ta[100010], tb[100010];

int main(){
    string s, t;
    cin >> s >> t;
    rep(i, s.size()){
        if (s[i] == 'A') sa[i+1]++;
        if (s[i] == 'B') sb[i+1]++;
    }
    rep(i, t.size()){
        if (t[i] == 'A') ta[i+1]++;
        if (t[i] == 'B') tb[i+1]++;
    }
    rep(i, s.size()) sa[i+1] += sa[i], sb[i+1] += sb[i];
    rep(i, t.size()) ta[i+1] += ta[i], tb[i+1] += tb[i];

    int q;
    cin >> q;
    vector<string> ans;
    
    while(q--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--, c--;
        int xa = sa[b] - sa[a];
        int xb = sb[b] - sb[a];
        int ya = ta[d] - ta[c];
        int yb = tb[d] - tb[c];
        if ((xa - xb - ya + yb) % 3 == 0) ans.push_back("YES");
        else ans.push_back("NO");
    }
    for (auto e:ans) cout << e << endl;
    return 0;
}
