#include <bits/stdc++.h>
using namespace std;
 
#define int long long
//#define uint __int128_t
 
#define pb push_back
#define fi first
#define se second
#define rep(i,s,n) for(int i = s;i<n;i++)
#define repe(i,s,n) for(int i = s;i<=n;i++)
#define rrep(i,s,n) for(int i = (n)-1;i>=(s);i--)
#define all(v) (v).begin(),(v).end()
#define chmin(a,b) a=min((a),(b))
#define chmax(a,b) a=max((a),(b))
#define low(a,b) lower_bound(all(a),(b))-(a).begin()
#define upp(a,b) upper_bound(all(a),(b))-(a).begin()
#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0)
typedef long long ll;
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<vint> vvint;
typedef vector<pint>vpint;
typedef pair<pint,int> P1;
typedef pair<int,pint> P2;
typedef pair<pint,pint> PP;
static const ll maxLL = (ll)1 << 62;
const ll MOD=1000000007;
const ll INF=1e18;
 
int W,H;
vpint v;

signed main() {
    IOS();
    //(1ll<<N)シフト演算のオーバーフローに気をつける
    //MOD同士の引き算に注意
    cin>>W>>H;
    v.resize(W+H);
    rep(i,0,W+H){
        int x;cin>>x;
        v[i]={x,i};
    }
    sort(all(v));
    int a=W+1,b=H+1,ans=0;
    rep(i,0,H+W){
        if(v[i].se<W){
            ans+=b*v[i].fi;
            a--;
        }else{
            ans+=a*v[i].fi;
            b--;
        }
    }
    cout<<ans<<endl;
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}