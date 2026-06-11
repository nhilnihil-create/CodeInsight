#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define bit(n) (1<<(n))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

int const MAX_w = 305;
ll dp[101][101][MAX_w + 5];

int main()
{
    int n; ll W;
    cin >> n >> W;
    vl w(n),v(n);
    rep(i,n) cin >> w[i] >> v[i];

    Fill(dp, 0);
    rep(i,n) rep(j,n) rep(k,MAX_w) {
        chmax(dp[i+1][j+1][k+w[i]-w[0]], dp[i][j][k] + v[i]);
        chmax(dp[i+1][j][k], dp[i][j][k]);
    }

    ll res = 0;
    rep(j,n+1) rep(k,MAX_w) {
        if(k <= W - j*w[0]) chmax(res, dp[n][j][k]);
    }
    cout << res << endl;
    return 0;
}