#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
using namespace std;
const long long int INF = 1e18;
const long long int mod = 1e9+7;

typedef pair<ll, ll> pairs;
typedef vector<pairs> p;

struct Edge{
    ll to, weight;
    Edge(ll t, ll w) : to(t), weight(w){}
};
using graph = vector<vector<ll>>;
using Graph = vector<vector<Edge>>;


ll gcd(ll a,ll b){
    if(b == 0){
        return a;
    }else{
        return gcd(b, a%b);
    }
}

ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}

ll keta(ll N){
    ll M = 1;
    while( N > 0 ){
        if(N / 10 == 0){
            break;
        }
        N /= 10;
        M++;
    }
    return M;
}

// 回文
bool kai(string S){
    bool flag = true;
    for(ll i=0;i<S.size()/2;++i){
        if(S[i] != S[S.size()-i-1]){
            flag = false;
            break;
        }
    }
    return flag;
}
// ---------------------------------------------

int main(){
    ll n, m;
    cin>>n>>m;
    ll g[n][n];
    for(ll i=0;i<n;++i){
        for(ll j=0;j<n;++j){
            if(i == j){
                g[i][j] = 0;
            }else{
                g[i][j] = INF;
            }
        }
    }
    vector<ll> a(m), b(m), c(m);
    for(ll i=0;i<m;++i){
        cin>>a[i]>>b[i]>>c[i];
        a[i]--;
        b[i]--;
        g[a[i]][b[i]] = min(g[a[i]][b[i]], c[i]);
        g[b[i]][a[i]] = min(g[b[i]][a[i]], c[i]);
    }

    for(ll k=0;k<n;++k){
        for(ll i=0;i<n;++i){
            for(ll j=0;j<n;++j){
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    ll ans = m;
    for(ll i=0;i<m;++i){
        bool flag = false;
        for(ll j=0;j<n;++j){
            if(g[j][a[i]] + c[i] == g[j][b[i]]){
                flag = true;
            }
        }
        if(flag){
            ans--;
        }
    }
    cout<<ans<<endl;

    return 0;
}