#include <bits/stdc++.h>
#define REP(i,s,e) for(int i=(s); i<(e);i++)
#define rep(i,n) REP(i,0,n)
#define rep1(i,n) REP(i,1,n)
#define repe(i,n) for(auto &&i:n)
#define all(v) (v).begin(),(v).end()
#define decimal fixed<<setprecision(20)
#define fastcin() cin.tie(0);ios::sync_with_stdio(false)
using namespace std;
using LL = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = 1e9;
const LL LLINF = 1e16;

int main(){
    fastcin();

    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    rep(i, n)rep(j, m) cin >> a[i][j];

    int ans = n;
    vector<int> play(m, 1), idx(n, 0);
    rep(i, m){
        vector<int> ct(m, 0);
        bool stop = 0;
        rep(j, n){
            int k = a[j][idx[j]]-1;
            while(!play[k]){
                idx[j]++;
                if(idx[j] >= m){
                    stop = 1;
                    break;
                }
                k = a[j][idx[j]]-1;
            }
            if(stop) break;
            ct[k]++;
        }
        if(stop) break;
        int max_sport = max_element(all(ct)) - ct.begin();
        // cout <<max_sport+1<<endl;
        chmin(ans, ct[max_sport]);
        play[max_sport] = 0;

    }
    cout << ans << endl;
}