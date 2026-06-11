#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define FILL(i,n) memset(i,n,sizeof i)
#define X first
#define Y second
#define ET cout << "\n"
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(),v.end()
#define pb push_back
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#ifdef bbq
#define debug(...) {\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}
#define DB(a,s,e) {for(int _i=s;_i<e;++_i) cerr << a[_i] << " ";cerr << "\n";}
template<typename T>void _do(T &&x){cerr<<x<<endl;}
template<typename T,typename ...S> void _do(T &&x,S &&...t){cerr<<x<<", ";_do(t...);}
template<typename a,typename b> ostream& operator << (ostream &s,const pair<a,b> &p){return s<<"("<<p.X<<","<<p.Y<<")";}
#else
#define debug(...)
#define DB(a,s,e)
#endif

const ll MOD=1e9+7;
ll dp[2005][2005],J[4000005],inv[4000005],invJ[4000005];

int main()
{
    IOS();
    ll n,k;
    cin >> n >> k,J[0]=J[1]=inv[1]=invJ[0]=invJ[1]=1,dp[0][0]=1;
    if(k==1)
        return cout << "1\n",0;
    for(ll i=2;i<=n*k;++i)
        J[i]=J[i-1]*i%MOD,inv[i]=(MOD-MOD/i)*inv[MOD%i]%MOD,invJ[i]=invJ[i-1]*inv[i]%MOD;
    for(int i=0;i<=n;++i)
        for(int j=i;j<=n;++j)
        {
            if(i)
                dp[i][j]=dp[i-1][j];
            if(i!=j)
                dp[i][j]=(dp[i][j]+dp[i][j-1]*J[i+j*(k-1)-1]%MOD*invJ[k-2]%MOD*invJ[i+j*(k-1)-k+1])%MOD;
        }
    cout << dp[n][n]*J[n]%MOD << "\n";
}