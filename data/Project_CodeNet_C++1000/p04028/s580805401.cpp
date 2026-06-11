#include <iostream>
#include <math.h>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const ll mod = 1000000007;
ll fact[200200];
ll invfact[200200];

inline ll take_mod(ll a){
    return (a % mod + mod) % mod;
}

inline ll add(ll a, ll b){
    return take_mod(a+b);
}

inline ll sub(ll a, ll b){
    return take_mod(a-b);
}


inline ll mul(ll a, ll b){
    return take_mod(a * b);
}

inline ll mod_pow(ll x, ll n){
    ll res = 1LL;
    while(n > 0){
        if(n & 1) res = mul(res, x);
        x = mul(x, x);
        n >>= 1;
    }
    return res;
}

ll mod_inv(ll x){
    return mod_pow(x, mod-2);
}

// nは上限
void make_fact(ll n){
    fact[0] = 1;
    ll res = 1;
    for(int i = 1; i <= n; i++){
        fact[i] = res;
        res = mul(res, i+1);
    }
}

// nは上限
void make_invfact(ll n){
    invfact[0] = 1;
    invfact[n] = mod_inv(fact[n]);
    for(int i = n-1; i >= 1; i--){
        invfact[i] = mul(invfact[i + 1], i + 1);
    }
}

ll perm(ll n, ll k){
    return mul(fact[n], invfact[n-k]);
}

ll comb(ll n, ll k){
    return mul(mul(fact[n], invfact[n-k]), invfact[k]);
}

ll dp[5100][5100];


int main() {
    int N;
    cin >> N;
    string s;
    cin >> s;
    int x = s.length();

    for(int i = 0; i < 5100; i++){
        for(int j = 0; j < 5100; j++){
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;

    for(int i = 0; i <= N-1; i++){
        for(int j = 0; j <= N-1; j++){
            dp[i+1][j+1] = add(dp[i+1][j+1], mul(dp[i][j], 2));
            dp[i+1][max(j-1, 0)] = add(dp[i+1][max(j-1, 0)], dp[i][j]);
        }
    }

//    cout << dp[N][x] << endl;
    cout << mul(dp[N][x], mod_inv(mod_pow(2, x))) << endl;

    return 0;
}