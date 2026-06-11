#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using ll = long long;
using P = pair<ll, ll>;
const long double PI = acos(-1.0L);
ll GCD(ll a, ll b) { return b?GCD(b, a%b):a; }
ll LCM(ll a, ll b) { return a/GCD(a, b)*b; }

const int INF = 1e9;

int n, m;
vector< vector<int> > G(110, vector<int>(110, INF));

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int a, b, c; cin >> a >> b >> c;
        a--; b--;
        G[a][b] = c;
        G[b][a] = c;
    }
    for(int i = 0; i < n; ++i) G[i][i] = 0;
    vector< vector<int> > Gsub = G;

    for(int k = 0; k < n; ++k) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                chmin(G[i][j], G[i][k]+G[k][j]);
            }
        }
    }

    int cnt = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(Gsub[i][j] != INF) {
                if(G[i][j] != Gsub[i][j]) cnt++;
            }
        }
    }
    cout << cnt/2 << endl;
}