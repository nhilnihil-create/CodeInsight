#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

int const INF = 1 << 30;
int const MAX = 405;
int dp[45][450][450];

int main()
{
    int n,ma,mb;
    cin >> n >> ma >> mb;
    vector<int> a(n),b(n),c(n);
    rep(i,n) cin >> a[i] >> b[i] >> c[i];

    Fill(dp, INF);
    dp[0][0][0] = 0;
    rep(i,n) rep(j,MAX) rep(k,MAX) {
        if(dp[i][j][k] >= INF) continue;
        chmin(dp[i+1][j][k], dp[i][j][k]);
        chmin(dp[i+1][j+a[i]][k+b[i]], dp[i][j][k] + c[i]);
    }

    int res = INF;//j = k = 0のときに注意
    for(int j = 1; j <= MAX; ++j) {
        for(int k = 1; k <= MAX; ++k) {
            if(mb*j == ma*k) chmin(res, dp[n][j][k]);
        }
    }
    cout << (res < INF?res:-1) << endl;
    return 0;
}