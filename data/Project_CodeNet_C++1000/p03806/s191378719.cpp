#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PI 3.141592653589793
#define rep(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, n) for (int i = a; i < (n); i++)
#define rrep(i, n, k) for (int i = (n); i >= (k); i--);
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
template<class T> istream &operator>>(istream&is,vector<T>&v){for(auto &elemnt:v)is>>elemnt;return is;}
template<class T,class U> istream &operator>>(istream&is,pair<T,U>&p){is>>p.first>>p.second;return is;}
template<class T>vector<T> make_vector(size_t a){return vector<T>(a);}
template<class T, class... Ts>auto make_vector(size_t a, Ts... ts){return vector<decltype(make_vector<T>(ts...))>(a, make_vector<T>(ts...));}
const int MOD = 1e9+ 7;
const int INF = 2e18;

struct info {
    int a, b, c;
};

signed main() {
    int N, Ma, Mb;
    cin >> N >> Ma >> Mb;
    vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(501, vector<int>(501, INF)));
    vector<info> store(N + 1);
    for (int i = 1; i <= N; i++) cin >> store[i].a >> store[i].b >> store[i].c;
    dp[0][0][0] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= 500; j++) {
            for (int k = 0; k <= 500; k++) {
                dp[i][j][k] = dp[i - 1][j][k];
                if (j - store[i].a >= 0 && k - store[i].b >= 0) dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j - store[i].a][k - store[i].b] + store[i].c);
                // if (j % Ma == 0 && k % Mb == 0) cout << i << " " << j << " " << k << endl;
            }
        }
    }
    int ans = INF;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= 500; j++) {
            for (int k = 1; k <= 500; k++) {
                if (Mb * j == Ma * k) ans = min(ans, dp[i][j][k]);
            }
        }
    }
    cout << (ans == INF ? -1 : ans) << endl;
}
