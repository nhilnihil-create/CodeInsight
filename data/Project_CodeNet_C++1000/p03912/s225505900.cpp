#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf=1e9+7;
const int mod=998244353;
int main(){
    ll n,m;cin>>n>>m;
    vector<ll>x(n);
    rep(i,n)cin>>x[i];
    sort(all(x));
    vector<ll>r(m);
    vector<ll>p(m);
    x.pb(0);
    rep(i,n){
        if(x[i]==x[i+1]){
            p[x[i]%m]+=2;
            r[x[i]%m]+=2;
            i++;continue;
        }
        r[x[i]%m]++;
    }
    ll ans=0;
    ans+=r[0]/2;
    if(!(m%2))ans+=r[m/2]/2;
    REP(i,1,(m+1)/2){
        ll a=p[i],b=p[m-i],c=r[i]-a,d=r[m-i]-b;
        if(c>=d){
            ans+=d;
            c-=d;
            if(c>=b){
                ans+=b;
                ans+=a/2;
            }else{
                ans+=c;
                b-=c;
                ans+=b/2;
                ans+=a/2;
            }
        }else{
            swap(c,d);
            swap(a,b);
            ans+=d;
            c-=d;
            if(c>=b){
                ans+=b;
                ans+=a/2;
            }else{
                ans+=c;
                b-=c;
                ans+=b/2;
                ans+=a/2;
            }
        }
    }
    cout<<ans<<endl;
}