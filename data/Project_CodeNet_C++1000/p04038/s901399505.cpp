# include <iostream>
# include <string>
# include <algorithm>
# include <vector>
# include <cstring>
# include <stdio.h>
# include <map>
# include <queue>

# define ll long long
# define pii pair<int,int>
# define FOR(a,b) for(int a=1; a<=b; a++)
# define REP(a,b) for(int a=0; a<b; a++)
# define FORU(a,b,c) for(int a=b; a<=c; a++)
# define FORD(a,b,c) for(int a=b; a>=c; a--)

using namespace std;

const ll mod = 1e9 + 7;
int N, K, dp[2005][2005];
ll f[4000005], inf[4000005];

ll mul(ll a, ll b){
    return ((a%mod)*(b%mod))%mod;
}

ll add(ll a, ll b){
    return ((a%mod)+(b%mod))%mod;
}

ll pw(ll b, ll e){
    if(e==0) return 1ll;
    ll t = pw(b,e/2);
    if(e&1) return mul(b,mul(t,t));
    return mul(t,t);
}

ll modinv(ll x){
    return pw(x, mod-2);
}

void precompute(){
    f[0] = inf[0] = 1ll;
    FOR(i,4000000){
        f[i] = mul(f[i-1], i);
        inf[i] = modinv(f[i]);
    }
}

ll C(ll n, ll r){
    if(n < r) return 0;
    return mul(f[n], mul(inf[n-r], inf[r]));
}

int main(){

    ios :: sync_with_stdio(false);
    cin >> N >> K;
    precompute();

    if(K==1){
        cout << 1 << endl;
        return 0;
    }
    
    REP(i,N+1){
        FORU(j,i,N){
            if(i==0 && j==0) dp[i][j] = 1;
            if(i-1 >= 0) dp[i][j] = dp[i-1][j];
            if(j > i){
                dp[i][j] = add(dp[i][j], mul(dp[i][j-1], C(i + j*(K-1) -1, K-2)));
            }
        }
    }

    ll ans = mul(dp[N][N], f[N]);
    cout << ans << endl;
    return 0;
}