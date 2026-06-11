#include <bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MAX 2000005
#define MOD 1000000007
#define MOD2 998244353
#define pb push_back
#define mp make_pair
#define pii pair<ll,ll>
#define vi vector<ll>
#define vp vector<pii>
#define all(v) v.begin(),v.end()
#define sz(x) (ll)x.size()
#define F first
#define S second
#define FOR(i,a,b) for(ll i=a;i<b;++i)
#define ROF(i,a,b) for(ll i=a;i>=b;--i)
#define trace(x) cerr<<#x<<": "<<x<<'\n';
typedef long long ll;
using namespace std;
//using namespace __gnu_pbds;
//#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

ll mexp(ll a, ll b){
    ll ans=1;
    a%=MOD;
    while(b){
        if(b&1) ans=ans*a%MOD;
        b>>=1;
        a=a*a%MOD;
    }
    return ans;
}

ll h,w,n;
map<pair<ll,ll>,bool> f;
vector<pair<ll,ll> >v;
set<pair<ll,ll> >s;

int calc(int x,int y){
    int c=0;
    FOR(i,-1,2){
        FOR(j,-1,2){
            if(x+i<1 || x+i>h || y+j<1 || y+j>w){
                return 0;
            }
            if(f[mp(x+i,y+j)]){
                c++;
            }
        }
    }
    s.insert(mp(x,y));
    return c;
}

int main(){
    IOS

    cin>>h>>w>>n;
    FOR(i,0,n){
        int x,y;
        cin>>x>>y;
        f[mp(x,y)]=1;
        v.pb(mp(x,y));
    }
    ll ans[10];
    FOR(i,0,10){
        ans[i]=0;
    }
    FOR(p,0,n){
        FOR(i,-1,2){
            FOR(j,-1,2){
                int x=v[p].F,y=v[p].S;
                if(s.find(mp(x+i,y+j))!=s.end()){
                    continue;
                }
                ans[calc(x+i,y+j)]++;
            }
        }
    }
    ll sum=0;
    FOR(i,1,10){
        sum+=ans[i];
    }
    ans[0]=(h-2)*(w-2)-sum;
    FOR(i,0,10){
        cout<<ans[i]<<endl;
    }
  
    cerr<<"Time: "<<1.0/CLOCKS_PER_SEC<<" ms"<<endl;
    return 0;
}