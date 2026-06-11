
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include <boost/multiprecision/cpp_int.hpp>
//typedef boost::multiprecision::cpp_int ll;
typedef long double dd;
#define i_7 (ll)(1E9+7)
//#define i_7 998244353
#define i_5 i_7-2
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    return c+i_7;
}
typedef pair<ll,ll> l_l;
ll inf=(ll)1E16;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll &pos,ll val){pos=max(pos,val);}//Max(dp[n],dp[n-1]);
void Min(ll &pos,ll val){pos=min(pos,val);}
void Add(ll &pos,ll val){pos=mod(pos+val);}
dd EPS=1E-9;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
////////////////////////////


#define N 100005
ll p[N+1];
vector<ll>chi[N+1];
vector<ll>v[N+1];
ll d[N+1];
void dfs(ll k){
    for(auto x:v[k]){
        if(p[x]==0){
            p[x]=k;
            chi[k].pb(x);
            d[x]=d[k]+1;
            dfs(x);
        }
    }
}
void no(){cout<<"NO"<<endl;}

int main(){fastio
    ll n;cin>>n;
    ll a[n+1];rep(i,1,n)cin>>a[i];
    rep(i,1,n-1){
        ll a,b;cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    p[1]=-1;dfs(1);
    vector<ll>dep[N];
    rep(i,1,n)dep[d[i]].pb(i);
    /*
    rep(i,0,5){
        cout<<i<<":";
        for(auto x:dep[i])cout<<x<<" ";cout<<endl;
    }
     */
    for(ll i=N-1;i>=0;i--){
        for(auto x:dep[i]){
            ll k;
            if(chi[x].size()==0)continue;
            ll sum=0,ma=0;
            for(auto y:chi[x]){
                Max(ma,a[y]);
                sum+=a[y];
            }
            if(a[x]>sum){
                no();return 0;
            }
            if(a[x]<ma||a[x]*2<sum){
                no();return 0;
            }
            a[x]-=(sum-a[x]);
            if(a[x]<0){
                no();return 0;
            }
        }
    }
    //rep(i,1,n)cout<<a[i]<<" ";cout<<endl;
    if(a[1]!=0){
        if(chi[1].size()==1){
            if(a[1]==a[chi[1][0]]){
                cout<<"YES";return 0;
            }
        }
        cout<<"NO"<<endl;
    }else cout<<"YES"<<endl;
    return 0;
}
