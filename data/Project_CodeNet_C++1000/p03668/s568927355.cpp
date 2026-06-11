#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include <boost/multiprecision/cpp_ll.hpp>
//typedef boost::multiprecision::cpp_ll ll;
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
ll inf=(ll)1E18;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll &pos,ll val){pos=max(pos,val);}//Max(dp[n],dp[n-1]);
void Min(ll &pos,ll val){pos=min(pos,val);}
void Add(ll &pos,ll val){pos=mod(pos+val);}
dd EPS=1E-9;
//#define endl "\n"
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

ll n;
struct Node{
    ll par;
    vector<ll> chi;
};
Node node[500001];
vector<ll> v[500001];
void init(ll x){
    rep(i,0,(ll)v[x].size()-1){
        if(v[x][i]!=node[x].par){
            node[x].chi.pb(v[x][i]);
            node[v[x][i]].par=x;
            init(v[x][i]);
        }
    }
}
void init(){
    cin>>n;
    rep(i,0,n-2){
        ll x,y;cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    node[1].par=1;
    init(1);
}

ll hoge(ll x){
    ll res=0;
    if(node[x].chi.size()==0){
        return 0;
    }else{
        rep(i,0,node[x].chi.size()-1){
            res=res^(hoge(node[x].chi[i])+1);
        }
        return res;
    }
}

int main(){fastio
    init();
    if(hoge(1)==0){
        cout<<"Bob"<<endl;
    }else{
        cout<<"Alice"<<endl;
    }
    
    return 0;
}



