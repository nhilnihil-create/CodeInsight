#include <bits/stdc++.h>
#include <math.h>
#include <float.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
 
const ll INF = 1LL<<62;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// 多次元 vector 生成
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
  return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
const int MOD = 1000000007;


int dp[41][401][401];

int main(){
    int N, Ma, Mb; cin >> N >> Ma >> Mb;
    vector<int> a(N), b(N), c(N);
    rep(i,N) cin >> a[i] >> b[i] >> c[i];

    rep(i,N+1){
        rep(j,401){
            rep(k,401){
                dp[i][j][k] = 100000000;
            }
        }
    }
    dp[0][0][0] = 0;
    rep(i,N){
        rep(j,401){
            rep(k,401){
                chmin(dp[i+1][j][k], dp[i][j][k]);
                if (j+a[i] > 400 || k+b[i] > 400) continue;
                chmin(dp[i+1][j+a[i]][k+b[i]],dp[i][j][k]+c[i]); 
            }
        }
    }
    const int max_v = 100000000;
    int ans = max_v;
    for (int i = 1; i <= 400; i++){
        for (int j = 1; j <= 400; j++){
            if (i*Mb == j*Ma){
                ans = min(ans, dp[N][i][j]);
            }
        }
    }

    if (ans == max_v) cout << -1 << endl;
    else cout << ans << endl;
    

}