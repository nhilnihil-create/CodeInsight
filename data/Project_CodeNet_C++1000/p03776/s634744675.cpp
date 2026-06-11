#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define cinf(n,x) for(int i=0;i<(n);i++)cin>>x[i];
#define ft first
#define sc second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(),(v).end()
#define mod 1000000007
using namespace std;
typedef long long ll;
template<class T> using V=vector<T>;
using Graph = vector<vector<int>>;
using P=pair<ll,ll>;
typedef unsigned long long ull;
typedef long double ldouble;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const ll INF=1e18;

ll com(ll n,ll k){
    if(k==1) return n;
    if(k==0||n==k) return 1;
    return com(n-1,k-1)+com(n-1,k);
}

int main(){
    ll n,a,b;
    cin>>n>>a>>b;
    vector<ll> v(n),s(n+1,0);
    cinf(n,v);
    sort(all(v));
    rep(i,n) s[i+1]=s[i]+v[i];
    set<P> st;//(分子,分母)
    for(ll i=a;i<=b;i++){
        ll m=s[n]-s[n-i];
        ll g=__gcd(i,m);
        ll aa=i/g,bb=m/g;
        if(st.empty()){
            st.insert(P(bb,aa));
        }else{
            P p=*begin(st);
            ll left=p.sc*bb;
            ll right=p.ft*aa;
            if(left>right){
                st.clear();
                st.insert(P(bb,aa));
            }else if(left==right){
                st.insert(P(bb,aa));
            }
        }
    }
    ll cnt=0;
    for(ll i=a;i<=b;i++){
        P p=*begin(st);
        ll m=s[n]-s[n-i];
        ll g=__gcd(i,m);
        ll aa=i/g,bb=m/g;
        ll left=p.sc*bb;
        ll right=p.ft*aa;
        if(left==right){
            ll m=n-i;
            ll r=ub(all(v),v[m])-v.begin();
            ll l=lb(all(v),v[m])-v.begin();
            ll x=1;
            ll y=2;
            for(ll j=m-l+1;j<=r-l;j++){
                x*=j;
                while(x%y==0&&y<=r-m){
                    x/=y;
                    y++;
                }
            }
            cnt+=x;
        }
    }
    P p=*begin(st);
    double ans=(double)p.ft/p.sc;
    cout<<fixed<<setprecision(10)<<ans<<endl;
    cout<<cnt<<endl;
}