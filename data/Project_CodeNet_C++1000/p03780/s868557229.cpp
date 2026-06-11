#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <iterator>
#include <map>
#include <set>
#include <iomanip>
#include <vector>
#include <cstdint>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using Graph = vector<vector<int>>;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
#define rep(i, N) for(int i = 0; i < N; i++)
#define rep2(i, l, r) for (ll i = (ll)l; i < (ll)(r); i++)
#define INF 1000000000000000
#define MAX 200001
#define PI 3.141592653589793

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
const ll MOD = 1000000007;

ll RepeatSquaring(ll n, ll p, ll mod){
    if(p == 0) return 1;
    if(p % 2 == 0){
        ll t = RepeatSquaring(n, p/2, mod);
        return t*t;
    }
    else return n * RepeatSquaring(n, p-1, mod);
}

int main(){
    ll N, K;
    cin >> N >> K;
    vector<ll> a(N);
    rep(i,N) cin >> a[i];
    vector<vector<ll>> dp(N+1,vector<ll>(K+1,0));
    rep(i,N) dp[i][0] = 1;
    rep(i,N)rep(j,K-1){
        if(j+1-a[i] < 0) dp[i+1][j+1] += dp[i][j+1];
        else dp[i+1][j+1] += dp[i][j+1] + dp[i][j+1-a[i]];
        dp[i+1][j+1] %= MOD;
    }
    ll sum = RepeatSquaring(2,N,MOD);
    sum--;
    rep(i,K-1){
        sum -= dp[N][i+1];
        if(sum < 0) sum += MOD;
        else sum %= MOD;
    }
    sort(a.begin(),a.end());
    ll left = -1;
    ll right = N;
    while(right-left > 1){
        ll mid = (left + right) / 2;
        int flag = 0;
        rep(i,N+1)rep(j,K+1){
            if(j == 0) dp[i][j] = 1;
            else dp[i][j] = 0;
        }
        rep(i,N)rep(j,K-1){
            if(i == mid){
                flag = 1;
                continue;
            }
            if(j+1-a[i] < 0) dp[i+1-flag][j+1] += dp[i-flag][j+1];
            else dp[i+1-flag][j+1] += dp[i-flag][j+1] + dp[i-flag][j+1-a[i]];
            dp[i+1-flag][j+1] %= MOD;
        }
        ll sum_sub = RepeatSquaring(2,N-1,MOD);
        sum_sub--;
        rep(i,K-1){
            sum_sub -= dp[N-1][i+1];
            if(sum_sub < 0) sum_sub += MOD;
            else sum_sub %= MOD;
        }
        if(sum % MOD == 2*sum_sub % MOD) left = mid;
        else right = mid;
    }
    cout << left + 1 << endl;
}
