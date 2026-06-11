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
using P = pair<ll,int>;
const int inf = 1e9;
const ll inf_l = 1e18;
const int MAX = 1e5;
const int mod = 1e9+7;

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
    int n, m; cin >> n >> m;
    vvint d(n,vint(n,inf));
    vvint data(m);
    rep(i,n) d[i][i] = 0;
    rep(i,m) {
        int a, b, c; cin >> a >> b >> c;
        a--; b--;
        d[a][b] = d[b][a] = c;
        data[i].push_back(a);
        data[i].push_back(b);
        data[i].push_back(c);
    }
    warshall_floyd(d,n);
    int ans = 0;
    rep(i,m) {
        if (d[data[i][0]][data[i][1]] != data[i][2]) ans++;
    }
    cout << ans << endl;
}