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

int t[110], p[110], x[110];
int score[110];

int main(){
    int n;
    cin >> n;
    int tot = 0;
    rep(i, n) cin >> t[i], tot += t[i];
    int m;
    cin >> m;
    rep(i, m){
        cin >> p[i] >> x[i];
        p[i]--;
    }
    rep(i, m) cout << tot - t[p[i]] + x[i] << endl;
    return 0;
}
