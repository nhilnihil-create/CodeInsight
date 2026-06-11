#include <bits/stdc++.h>
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define IFOR(i, begin, end) for(int i=(end)-1;i>=(begin);i--)
#define IREP(i, n) IFOR(i,0,n)
#define SORT(a) sort(a.begin(), a.end())
#define REVERSE(a) reverse(a.begin(), a.end())
#define Lower_bound(v, x) distance(v.begin(), lower_bound(v.begin(), v.end(), x))
#define Upper_bound(v, x) distance(v.begin(), upper_bound(v.begin(), v.end(), x))
#define int long long
#define INF 1000000000000000000
using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;
typedef pair<int, int> Pii;

template<typename T>
void readvec(vector<T> &a);
void readindex(vector<int> &a);

int fastpow(int x, int n, int m){
    int a = 1;
    IREP(i, 64){
        a = (a * a) % m;
        if(((n >> i) & 1) == 1) a = (a * x) % m;
    }
    return (int)a;
}

signed main(){

    int N; cin >> N;
    string s; cin >> s;
    int mod = 1000000007;

    mat dp(N + 1, vec(N + 2, 0));
    dp[0][0] = 1;
    REP(n, N){
        dp[n + 1][0] = (dp[n][0] + dp[n][1]) % mod;
        FOR(k, 1, n + 2) dp[n + 1][k] = (dp[n][k - 1] * 2 + dp[n][k + 1]) % mod;
    }
    int ans = dp[N][s.size()];
    int a = fastpow(2, s.size(), mod);
    ans *= fastpow(a, mod - 2, mod);
    ans %= mod;
    cout << ans;
    
    return 0;
}


template<typename T>
void readvec(vector<T> &a){
    REP(i, a.size()){
        cin >> a[i];
    }
}
void readindex(vector<int> &a){
    REP(i, a.size()){
        cin >> a[i];
        a[i]--;
    }
}