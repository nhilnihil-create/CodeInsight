#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define vout(x) rep(i,x.size()) cout << x[i] << " "
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
template<class T> bool chmax(T &a, T b) {if(a<b) {a=b;return 1;}return 0;}
using namespace std;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<int,int>;
const int inf = 1e9;
const ll inf_l = 1LL<<62;
const int MAX = 1e5;

// warshall_floyd
void warshall_floyd(vvint &d, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (d[j][i] == inf || d[i][k] == inf) continue;
                d[j][k] = min(d[j][k],d[j][i]+d[i][k]);
            }
        }
    }
}

int main() {
    int n, m, R; cin >> n >> m >> R;
    vint r(R);
    rep(i,R) {
        int x; cin >> x;
        x--;
        r[i] = x;
    }
    sort(all(r));
    vvint dis(n,vint(n,inf));
    rep(i,n) dis[i][i] = 0;
    rep(i,m) {
        int a, b, c; cin >> a >> b >> c;
        a--; b--;
        dis[a][b] = dis[b][a] = c;
    }
    warshall_floyd(dis,n);
    int ans = inf;
    do {
        int sum = 0;
        REP(i,R) sum += dis[r[i-1]][r[i]];
        ans = min(ans,sum);
    } while (next_permutation(all(r)));
    cout << ans << endl;
}