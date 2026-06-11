#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define Graph vector<vector<int>>
typedef long long ll;
const int INF = 1000000007;

// #include <boost/multiprecision/cpp_dec_float.hpp>
// #include <boost/multiprecision/cpp_int.hpp>
// namespace mp = boost::multiprecision;
// using Bint = mp::cpp_int;
// using Real = mp::number<mp::cpp_dec_float<1024>>;

int main(){
    int N, A;
    cin >> N >> A;
    vector<int> X(N+1);
    for(int i = 1; i <= N; i++){
        cin >> X[i];
    } 

    vector<vector<vector<ll>>> dp(N + 1, vector<vector<ll>>(N + 1, vector<ll>(N * A + 1, 0)));
    dp[0][0][0] = 1;

    for(int j = 0; j <= N; j++){
        for(int k = 0; k <= N; k++){
            for(int s = 0; s <= N * A; s++){
                if(j >= 1 && s < X[j]){
                    dp[j][k][s] = dp[j-1][k][s];
                } else if(j >= 1 && k >= 1 && s >= X[j]){
                    dp[j][k][s] = dp[j-1][k][s] + dp[j-1][k-1][s-X[j]];
                }
            }
        }
    }

    ll ans = 0;
    for(int i = 1; i <= N; i++){
        ans += dp[N][i][i*A];
    }

    cout << ans << endl;
}