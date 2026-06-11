#pragma GCC target ("avx2")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#include "bits/stdc++.h"
#include <unordered_set>
#include <unordered_map>
#include <random>
using namespace std;
typedef long long ll;
const ll MOD = 1'000'000'007LL; /*998'244'353LL;*/
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
const int dx[4]={ 1,0,-1,0 };
const int dy[4]={ 0,1,0,-1 };

int N;
ll A, B;
ll X[100000];

ll dp[100000][2];

signed main(){
    cin >> N >> A >> B;
    rep(i, N){
        cin >> X[i];
    }

    ll m1 = LLONG_MAX, m2 = LLONG_MAX;
    for(int i=N-1; i>=0; i--){
        if(i == N-1){
            rep(j, 2) dp[i][j] = 0;
            m1 = min(m1, dp[i][0]+A*X[i]);
            m2 = min(m2, dp[i][0]+2*A*X[i]);
            continue;
        }
        rep(j, 2){
            dp[i][j] = 1e16;
            dp[i][j] = min(dp[i][j], m1-A*X[i+1]+B);
            dp[i][j] = min(dp[i][j], m2-2*A*X[i+1]+B);
            if(j == 1) dp[i][j] = min(dp[i][j], dp[i+1][1]+A*(X[i+1]-X[i]));
        }
        m1 = min(m1, dp[i][0]+A*X[i]);
        m2 = min(m2, dp[i][0]+2*A*X[i]);
    }
    cout << dp[0][1] << endl;
}