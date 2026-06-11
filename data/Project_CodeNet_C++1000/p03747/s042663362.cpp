#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp> namespace mp = boost::multiprecision; //mp::cpp_intで宣言
using namespace std;
typedef long long ll;
#define i_7 (ll)(1E9+7)
#define i_5 (ll)(1E9+5)
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    else return c+i_7;
}
typedef pair<int,int> i_i;
typedef pair<ll,ll> l_l;
ll inf=(ll)1E12;//10^12
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll * pos,ll val){*pos=max(*pos,val);}//Max(&dp[i][j],dp[i-1][j]);
void Min(ll * pos,ll val){*pos=min(*pos,val);}
void Add(ll * pos,ll val){*pos=mod(*pos+val);}
const long double EPS=1E-8;
////////////////////////////////////////

struct ant{
    ll x;
    ll w;
    ll num;
};
bool comp(ant a,ant b){
    if(a.x<b.x)return true;
    else return false;
}

int main(){
    ll n,l,t;cin>>n>>l>>t;
    ant an[n];
    rep(i,0,n-1){
        cin>>an[i].x>>an[i].w;
        an[i].num=i;
    }
    vector<ant>v;
    rep(i,0,n-1){
        ll c;
        if(an[i].w==1){
            c=(an[i].x+t)%l;
        }else{
            c=(100000*l+an[i].x-t)%l;
            if(c<0)c+=l;
        }
        ant a;a.x=c;a.w=an[i].w;a.num=i;
        v.pb(a);
    }
    sort(v.begin(),v.end(),comp);
    
    ll count=0;
    ll pos;
    rep(i,0,n-1){
        if(v[i].num==0)pos=i;
    }
    ll init=-1;
    if(an[0].w==1){
        rep(i,1,n-1){
            if(an[i].w==2){
                ll q=2*t-(an[i].x-an[0].x);
                if(q<0)continue;
                else{
                    ll c=(q-1)/l;
                    count+=c+1;
                }
            }
        }
        init=(pos-count+n*1000000)%n;
        if(init<0)init+=n;
    }else{
        rep(i,1,n-1){
            if(an[i].w==1){
                ll q=2*t-(-an[i].x+l+an[0].x);
                if(q<0)continue;
                else{
                    ll c=q/l;
                    count+=c+1;
                }
            }
        }
        init=(pos+count+n*5)%n;
        if(init<0)init+=n;
    }
    //cout<<pos<<" "<<count<<" "<<init<<endl;
    rep(i,init,n-1){
        cout<<v[i].x<<endl;
    }
    rep(i,0,init-1){
        cout<<v[i].x<<endl;
    }
    return 0;
}
