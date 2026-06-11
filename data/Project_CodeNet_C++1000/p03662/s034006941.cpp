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

struct node{ ll pa,point;};
node no[100010];
vector<vector<ll>> v(100000);

ll Struct(ll x){
    if(x==1){
        ll sum=0;
        rep(i,0,v[x].size()-1){
            no[v[x][i]].pa=x;
            sum+=Struct(v[x][i]);
        }
        no[x].point=sum+1;
        return no[x].point;
    }else{
        ll sum=0;
        rep(i,0,v[x].size()-1){
            if(v[x][i]!=no[x].pa){
                no[v[x][i]].pa=x;
                sum+=Struct(v[x][i]);
            }
        }
        no[x].point=sum+1;
        return no[x].point;
    }
    
}

            
int main(){
    ll n;cin>>n;
    ll a[n],b[n];
    rep(i,0,n-2){
        cin>>a[i]>>b[i];
        v[a[i]].pb(b[i]);
        v[b[i]].pb(a[i]);
    }
    no[1].pa=0;
    Struct(1);
    ll x=n;
    vector<ll> vv;
    vv.pb(no[x].point);
    while(x!=1){
        x=no[x].pa;
        vv.pb(no[x].point);
    }
    reverse(vv.begin(),vv.end());
    ll k=(vv.size()+1)/2;
    ll ans=vv[0]-2*vv[k];
    if(ans>0){
        cout<<"Fennec"<<endl;
    }else{
        cout<<"Snuke"<<endl;
    }
    
    return 0;
}
