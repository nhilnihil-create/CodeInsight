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
//V,P(大文字)使用不可
//乗算の際にオーバーフローに注意せよ！！（適切にmodをとれ）
//制約をよく読め！

const ll INF=1e18;

signed main(){
    ll n;
    cin>>n;
    V<pair<ll,ll>> a(n);
    rep(i,n){
        ll aa;
        cin>>aa;
        a[i]=make_pair(aa,i);
    }
    sort(all(a));
    set<ll> pos,neg;
    ll ans=0;
    for(int i=0;i<n;i++){
        if(i==0){
            ans+=(a[i].sc+1)*(n-a[i].sc);
        }else{
            if(a[i].sc<*begin(pos)){
                ans+=a[i].ft*(*begin(pos)-a[i].sc)*(a[i].sc+1);
            }else if(a[i].sc>*rbegin(pos)){
                ans+=a[i].ft*(n-a[i].sc)*(a[i].sc-*rbegin(pos));
            }else{
                ll u=a[i].sc+*neg.ub(-a[i].sc);
                ll v=*pos.ub(a[i].sc)-a[i].sc;
                ans+=a[i].ft*(u*v);
            }
        }
        pos.insert(a[i].sc);
        neg.insert(-a[i].sc);
    }
    cout<<ans<<endl;
}