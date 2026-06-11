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
int dp[41][1000][1000];
int main() {
    int N, ma, mb;
    cin >> N >> ma >> mb;
    int a[N], b[N], c[N];
    rep(i, N){
        cin >> a[i] >> b[i] >> c[i];
    }

    rep(i, N+1){
        rep(j, 1000){
            rep(k, 1000){
                dp[i][j][k] = 11111111;
            }
        }
    }

    dp[0][0][0] = 0;
    rep(i, N){
        rep(j, 1000){
            rep(k, 1000){
                if (j - a[i] >= 0 && k - b[i] >= 0) {
                    dp[i + 1][j][k] = min(dp[i][j][k], dp[i][j - a[i]][k - b[i]] + c[i]);
                } else {
                    dp[i + 1][j][k] = dp[i][j][k];
                }
            }
        }
    }

    int ans = 10000000;
    REP(j, 1,1000){
        REP(k,1, 1000){
            if (j % ma == 0 && k % mb == 0 && j/ma == k/mb){
                ans = min(dp[N][j][k], ans);
            }
        }
    }

    if (ans == 10000000){
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}
