#include <bits/stdc++.h>
#define ft first
#define sc second
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define pt(sth) cout << sth << "\n"
#define chmax(a, b) {if(a<b) a=b;}
#define chmin(a, b) {if(a>b) a=b;}
#define moC(a, s, b) (a)=((a)s(b)+MOD)%MOD
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef map<ll, ll> Map;
static const ll INF=1e18;
static const ll MAX=1e5+7;
static const ll MOD=1e9+7;
ll max(ll a, ll b) {return a>b ? a:b;}
ll min(ll a, ll b) {return a<b ? a:b;}


ll N, K;
ll a[5050];
ll dp[5050][5050];

ll C(ll id) {
    vector<ll> b;
    ll i, j;
    for(i=0; i<N; i++) {
        if(i==id) continue;
        b.pb(a[i]);
    }
    
    for(i=0; i<=N; i++)
        for(j=0; j<=K; j++)
            dp[i][j]=0;
    
    dp[0][0]=1;
    for(i=0; i<N-1; i++) {
        for(j=0; j<=K; j++) {
            dp[i+1][j]|=dp[i][j];
            
            if(j+b[i]<=K)
                dp[i+1][j+b[i]]|=dp[i][j];
        }
    }
    
    ll f=0;
    for(i=max(0, K-a[id]); i<K; i++)
        if(dp[N-1][i]) f=1;
    
    if(f) return 1;
    else return 0;
    
}

int main(void) {
    cin >> N >> K;
    ll i;
    
    for(i=0; i<N; i++) cin >> a[i];
    sort(a, a+N);
    
    if(C(0)) {
        pt(0);
        return 0;
    }
    
    
    ll l=0, r=N;
    while(l+1<r) {
        ll mid=(l+r)/2;
        if(C(mid)) r=mid;
        else l=mid;
    }
    
    pt(l+1);
    
}





