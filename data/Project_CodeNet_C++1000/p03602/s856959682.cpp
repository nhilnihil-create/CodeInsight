#include<bits/stdc++.h>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define dump(a) (cerr << #a << "=" << (a) << endl)
#define DUMP(list) cout << "{ "; for(auto nth : list){ cout << nth << " "; } cout << "}" << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }


using namespace std;

int main(){
    ll dist[333][333];

    int n;
    cin >> n;
    vector<vector<ll>> e(n, vector<ll> (n));
    vector<pair<ll, pair<ll, ll>>> edge;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> e[i][j];

        }
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            int good = 1;
            for (int x = 0; x < n; x++) {
                if (i == j || i == x || j == x) continue;
                if (e[x][j] + e[x][i] < e[i][j]) {
                    cout << "-1\n";
                    return 0;
                }
                if (e[x][j] + e[x][i] == e[i][j]) good = 0;
            }
            ans += e[i][j] * good;
        }
    }

    cout << ans << endl;



}
