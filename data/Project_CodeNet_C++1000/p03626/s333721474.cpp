#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repl(i,l,r) for(ll i=(l);i<(r);i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define lper(i,r,l) for(ll i=r-1;i>=l;i--)
#define fi first
#define se second
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define CST(x) cout<<fixed<<setprecision(x)
using ll=long long;
using vl=vector<ll>;
using vvl=vector<vector<ll>>;
using pl=pair<ll,ll>;
const ll MOD=1000000007;
const ll MOD9=998244353;
const int inf=1e9+10;
const ll INF=4e18;
const ll dy[4]={1,0,-1,0};
const ll dx[4]={0,-1,0,1};
int main(){
    ll N;scanf("%lld",&N);
    char S[N],T[N];
    scanf("%s %s",S,T);
    ll ans;char now;
    rep(i,N){
        if(i==0){
            if(S[i]==T[i])ans=3,now='X';
            else ans=6,now='Y',i++;
        }
        else if(S[i]==T[i]){
            if(now=='X')ans*=2;
            else now='X';
        }
        else{
            if(now=='X')ans*=2,now='Y',i++;
            else ans*=3,i++;
        }
        ans%=MOD;
    }
    printf("%lld %s",ans,"\n");
    return 0;
}