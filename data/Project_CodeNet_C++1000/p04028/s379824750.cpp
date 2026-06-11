#include <bits/stdc++.h>
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define IFOR(i, begin, end) for(int i=(end)-1;i>=(begin);i--)
#define IREP(i, n) IFOR(i,0,n)
#define SORT(a) sort(a.begin(), a.end())
#define REVERSE(a) reverse(a.begin(), a.end())
#define Lower_bound(v, x) distance(v.begin(), lower_bound(v.begin(), v.end(), x))
#define Upper_bound(v, x) distance(v.begin(), upper_bound(v.begin(), v.end(), x))
#define ll long long
#define INF 1000000000000000000
using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;
typedef pair<int, int> Pii;

template<typename T>
void readvec(vector<T> &a);
void readindex(vector<int> &a);

int fastpow(int x, int n, int m){
    ll a = 1;
    IREP(i, 32){
        a = (a * a) % m;
        if(((n >> i) & 1) == 1) a = (a * x) % m;
    }
    return (int)a;
}

signed main(){

    int N; cin >> N;
    string s; cin >> s;
    int mod = 1000000007;

    //n回後に空文字となる場合の数 0,1区別
    mat dp(N + 1, vec(N + 2, 0));
    dp[0][0] = 1;
    FOR(n, 1, N + 1){
        ll tmp = ((ll)dp[n - 1][0] + (ll)dp[n - 1][1]) % mod;
        dp[n][0] = (int)tmp;
        FOR(k, 1, n + 1){
            ll tmp = (2 * (ll)dp[n - 1][k - 1] + (ll)dp[n - 1][k + 1]) % mod;
            dp[n][k] = (int)tmp;
        }
    }

    //0から1へ　1から|S|へ
    mat dp2(N + 1, vec(N + 2, 0));
    dp2[1][1] = 1;
    FOR(n, 2, N + 1){
        FOR(k, 1, n + 1){
            ll tmp = ((ll)dp2[n - 1][k - 1] + (ll)dp2[n - 1][k + 1]) % mod;
            dp2[n][k] = (int)tmp;
        }
    }

    ll ans = 0;
    int n = s.size();
    REP(i, N + 1){
        if(N - i - n < 0 || (N - i - n) % 2 != 0) continue;
        int del = (N - i - n) / 2;
        //cout << dp[i][0] << "," << dp2[N - i][n] << endl;
        ans += (ll)dp[i][0] * (((ll)dp2[N - i][n] * (ll)fastpow(2, del, mod)) % mod);
        ans %= mod;
    }
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