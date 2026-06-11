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
ll inf=(ll)1E17;
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
//区間和
struct RSQ{
    ll n;
    vector<ll>data;
    RSQ(ll vs){
        n=1;
        while(n<vs)n*=2;
        data.resize(2*n-1,0);
    }
    void update(ll k,ll a){
        k+=n-1;
        data[k]=mod(a);
        while(k>0){
            k=(k-1)/2;
            data[k]=mod(data[2*k+1]+data[2*k+2]);
        }
    }
    /*
    void add(ll k,ll a){
        k+=n-1;
        data[k]+=a;
        while(k>0){
            k=(k-1)/2;
            data[k]=data[2*k+1]+data[2*k+2];
        }
    }
     */
    ll query(ll a,ll b,ll k,ll l,ll r){
        if(r<=a||b<=l)return 0;
        if(a<=l&&r<=b){
            return data[k];
        }else{
            ll vl=query(a,b,2*k+1,l,(l+r)/2);
            ll vr=query(a,b,2*k+2,(l+r)/2,r);
            return mod(vl+vr);
        }
    }
    ll query(ll a,ll b){return query(a,b,0,0,n);}//[a,b)の和
};
//////////////////////////////////////////////////////
ll n,ans=0;
vector<ll>v;
bool check(){
    rep(i,0,n-2){
        ll k=v[i+1];
        for(ll j=i+2;j<=n-1&&j<=i+v[i];j++){
            if(v[j]!=k)return false;
        }
    }
    rep(i,0,n-1)cout<<v[i]<<" ";cout<<endl;
    ans++;
    return 0;
}
void dfs(ll c){
    c++;
    if(c==n){
        check();
    }else{
        rep(i,1,n){
            v.pb(i);
            dfs(c);
            v.pop_back();
        }
    }
}
int main(){
    cin>>n;
    if(n==1){
        cout<<1;return 0;
    }
    RSQ r(n+1);
    r.update(1,n);
    r.update(2,mod(n*n));
    rep(m,3,n){
        ll sum=mod((n-m+2)*n);
        Add(sum,(m-3)*(n-1));
        Add(sum,r.query(m-1,m));
        Add(sum,r.query(1,m-2));
        r.update(m,sum);
    }
    cout<<mod(r.query(n,n+1))<<endl;
    /*
    rep(i,1,n){
        cout<<i<<":"<<mod(r.query(i,i+1))<<endl;
    }
    
    dfs(-1);
    cout<<ans<<endl;
    */
    return 0;
}
