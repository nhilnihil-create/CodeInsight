#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)  for(long long i=0;i<(long long)(n);i++)
#define REP(i,k,n) for(long long i=k;i<(long long)(n);i++)
#define all(a) a.begin(),a.end()
#define pb push_back
#define eb emplace_back
#define lb(v,k) (lower_bound(all(v),k)-v.begin())
#define ub(v,k) (upper_bound(all(v),k)-v.begin())
#define fi first
#define se second
#define pi M_PI
#define PQ(T) priority_queue<T>
#define SPQ(T) priority_queue<T,vector<T>,greater<T>>
#define dame(a) {out(a);return 0;}
#define decimal cout<<fixed<<setprecision(15);
typedef long long ll;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> PP;
typedef tuple<ll,ll,ll,ll> PPP;
typedef multiset<ll> S;
using vi=vector<ll>;
using vvi=vector<vi>;
using vvvi=vector<vvi>;
using vp=vector<P>;
using vvp=vector<vp>;
using vb=vector<bool>;
using vvb=vector<vb>;
const ll inf=1001001001001001;
const int INF=1001001001;
const int mod=1000000007;
const double eps=1e-10;
template<class T> bool chmin(T&a,T b){if(a>b){a=b;return true;}return false;}
template<class T> bool chmax(T&a,T b){if(a<b){a=b;return true;}return false;}
template<class T> void out(T a){if((ll)(a)==inf)cout<<"inf"<<'\n';else if((ll)(a)==-inf)cout<<"-inf"<<'\n';else cout<<a<<'\n';}
template<class T,class U> void outs(T a,U b){if((ll)(a)>=inf-100||(ll)(a)<=-inf+100)out(b);else out(a);}
template<class T> void outp(T a){cout<<'('<<a.fi<<','<<a.se<<')'<<'\n';}
template<class T> void outvp(T v){rep(i,v.size())cout<<'('<<v[i].fi<<','<<v[i].se<<')';cout<<'\n';}
template<class T> void outvvp(T v){rep(i,v.size())outvp(v[i]);}
template<class T> void outv(T v){rep(i,v.size()){if(i)cout<<' ';if((ll)(v[i])==inf)cout<<"inf";else if((ll)(v[i])==-inf)cout<<"-inf";else cout<<(ll)(v[i]);}cout<<'\n';}
template<class T> void outvv(T v){rep(i,v.size())outv(v[i]);}
template<class T> bool isin(T x,T l,T r){return (l)<=(x)&&(x)<=(r);}
template<class T> void yesno(T b){if(b)out("yes");else out("no");}
template<class T> void YesNo(T b){if(b)out("Yes");else out("No");}
template<class T> void YESNO(T b){if(b)out("YES");else out("NO");}
template<class T> void noyes(T b){if(b)out("no");else out("yes");}
template<class T> void NoYes(T b){if(b)out("No");else out("Yes");}
template<class T> void NOYES(T b){if(b)out("NO");else out("YES");}
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
ll modpow(ll a,ll b){a%=mod;if(b==0)return 1;if(b&1)return a*modpow(a,b-1)%mod;ll k=modpow(a,b/2);return k*k%mod;}
const int l=20;
vvi table;
void init(int n){
    table=vvi(l,vi(n));
    REP(i,1,l){
        rep(j,n){
            if(table[i-1][j]!=-1)table[i][j]=table[i-1][table[i-1][j]];
            else table[i][j]=-1;
        }
    }
}
int main(){
    ll n,t,q;cin>>n;
    vi v(n);
    rep(i,n)cin>>v[i];
    cin>>t>>q;
    ll sum=0,r=0;
    vvi table(l,vi(n));
    rep(i,n){
        while(r<n-1){
            if(sum+v[r+1]-v[r]<=t){
                sum+=v[r+1]-v[r];
                r++;
            }
            else break;
        }
        table[0][i]=r;
        if(i<n-1)sum-=v[i+1]-v[i];
    }
    REP(i,1,l){
        rep(j,n){
            if(table[i-1][j]!=-1)table[i][j]=table[i-1][table[i-1][j]];
            else table[i][j]=-1;
        }
    }
    rep(tt,q){
        ll a,b;cin>>a>>b;
        a--;b--;
        if(a>b)swap(a,b);
        ll ans=0;
        for(int i=l-1;i>=0;i--){
            if(table[i][a]>=b)continue;
            a=table[i][a];
            ans+=1<<i;
        }
        out(ans+1);
    }
}