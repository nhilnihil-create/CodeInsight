#include<bits/stdc++.h>
//ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<pii,int> ppii;
typedef pair<int,pii> pipi;
typedef pair<ll,ll> pll;
typedef pair<pll,ll> ppll;
typedef pair<ll,pll> plpl;
typedef tuple<ll,ll,ll> tl;
ll mod=1000000007;
ll mod2=998244353;
ll mod3=1000003;
ll mod4=998244853;
ll inf=1000000000000000000;
double pi=2*acos(0);
#define rep(i,m,n) for(ll i=m;i<n;i++)
#define rrep(i,n,m) for(ll i=n;i>=m;i--)
int dh[4]={1,-1,0,0};
int dw[4]={0,0,1,-1};
int ddh[8]={-1,-1,-1,0,0,1,1,1};
int ddw[8]={-1,0,1,-1,1,-1,0,1};
ll lmax(ll a,ll b){
    if(a<b)return b;
    else return a;
}
ll lmin(ll a,ll b){
    if(a<b)return a;
    else return b;
}
ll gcd(ll a,ll b){
    if(a<b)swap(a,b);
    if(b==0)return a;
    if(a%b==0)return b;
    return gcd(b,a%b);
}
ll Pow(ll n,ll k){
    ll ret=1;
    ll now=n;
    while(k>0){
        if(k&1)ret*=now;
        now*=now;
        k/=2;
    }
    return ret;
}


void out(ll n){
    cout<<"? "<<n<<endl;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int c=1;
    for(ll i=9;;i=i*10+9){
        out(i);
        string s;cin>>s;
        if(s=="Y"){
            break;
        }
        else{
            c++;
        }
        if(i==999999999)break;
    }
    if(c==1){
        
        out(10);string t;cin>>t;
        if(t=="N"){
        for(ll i=20;i<100;i+=10){
            out(i);
            string s;cin>>s;
            if(s=="Y"){
                cout<<"! "<<i/10<<endl;
                return 0;
            }
        }
        }
        int r=0;
        for(ll i=10;;i*=10){
            out(i);
            string s;cin>>s;
            if(s=="N"){
                r=1;
                
                break;
            }
            c++;
            if(i==1000000000)break;
        }
        if(r==0){
            cout<<"! "<<1<<endl;
            return 0;
        }
        
    }
    if(c==10){
        cout<<"! "<<1000000000<<endl;
        return 0;
    }
    ll ans=0;
    for(ll i=0;i<c-1;i++){
        int u=10,d=0;
        while(u-d>1){
            int mid=(u+d)/2;
            out(ans+mid);
            string s;cin>>s;
            if(s=="Y"){
                d=mid;
            }
            else{
                u=mid;
            }
        }
        ans+=d;
        ans*=10;
    }
    ll now=ans;
    ll u=9,d=-1;
    while(u-d>1){
        ll mid=(u+d)/2;
        ll r=now+mid;
        r*=10;
        r+=9;
        cout<<"? "<<r<<endl;
        string s;cin>>s;
        if(s=="Y")u=mid;
        else d=mid;
    }
    ans+=u;
    cout<<"! "<<ans<<endl;
}
