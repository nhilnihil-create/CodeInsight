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

l_l cal(vector<ll>&v){
    sort(v.begin(),v.end());
    ll sum=0;
    l_l res=l_l(0,0);
    if(v.size()==0)return res;
    rep(i,0,v.size()-1){
        ll c=1;
        while(i<=v.size()-2&&v[i]==v[i+1]){
            c++;i++;
        }
        sum+=c/2;
    }
    res=l_l(v.size(),sum);
    return res;
}
ll c(l_l a,l_l b){
    ll res=0;
    if(a.first<b.first)swap(a,b);
    res=min((a.first+b.first)/2,b.first+a.second);
    return res;
}
int main(){fastio
    ll n,m;cin>>n>>m;
    ll x[n];rep(i,0,n-1)cin>>x[i];
    vector<ll>v[m];
    rep(i,0,n-1){
        v[x[i]%m].pb(x[i]);
    }
    l_l sco[m];
    rep(i,0,m-1){
        sco[i]=cal(v[i]);
    }
    //rep(i,0,m-1)cout<<sco[i].first<<" "<<sco[i].second<<endl;
    ll ans=0;
    rep(i,0,m/2){
        if((i*2)%m==0){
            ans+=(sco[i].first)/2;
        }else{
            ans+=c(sco[i],sco[m-i]);
        }
        //cout<<i<<":"<<ans<<endl;
    }
    cout<<ans<<endl;
    
    
    return 0;
}

