
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define i_7 (ll)(1E9+7)
//#define i_7 998244353
#define i_5 i_7-2
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    else return c+i_7;
}
typedef pair<ll,ll> l_l;
ll inf=(ll)1E17;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll &pos,ll val){pos=max(pos,val);}//Max(dp[n],dp[n-1]);
void Min(ll &pos,ll val){pos=min(pos,val);}
void Add(ll &pos,ll val){pos=mod(pos+val);}
long double EPS=1E-9;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
////////////////////////////////////////
void No(){
    cout<<"Impossible"<<endl;
}
#define no {No();return 0;}

multiset<ll>s;
bool era(ll n){
    auto itr=s.find(n);
    bool f=itr==s.end();
    if(f)return f;
    s.erase(itr);
    return f;
}

int main(){fastio;
    ll m;cin>>m;
    rep(i,1,m){
        ll c;cin>>c;s.insert(c);
    }
    ll mi=*s.begin();
    ll mx=*(--s.end());
    //cout<<mi<<" "<<mx<<endl;
    if(mx%2==0){
        ll n=mx/2;
        if(mi<n)no
        if(era(n))no
        rep(i,n+1,2*n){
            rep(j,1,2){
                if(era(i))no
            }
        }
    }else{
        ll n=mx/2;
        if(mi<n+1)no;
        rep(i,n+1,2*n+1){
            rep(j,1,2){
                if(era(i))no
            }
        }
    }
    if(s.find(mi)!=s.end())no
    cout<<"Possible"<<endl;
    return 0;
}



