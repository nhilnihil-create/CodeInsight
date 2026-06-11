#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;
const ll inf=1e9+7;
const ll mod=998244353;
int main(){
    ll n;cin>>n;
    vector<ll>a(n+1);
    rep(i,n){
        ll b;cin>>b;
        a[b]=i+1;
    }
    set<ll>st1,st2;
    ll ans=0;
    REP(i,1,n+1){
        ll r=n,l=1;
        ll now=a[i];
        auto itr1=st1.lower_bound(now),itr2=st2.lower_bound(-now);
        if(itr1!=st1.end()){
            r=*itr1-1;
        }
        if(itr2!=st2.end()){
            l=1-*itr2;
        }
        //cout<<now<<' '<<l<<' '<<r<<endl;
        ans+=(r-now+1)*(now-l+1)*i;
        st1.insert(now);
        st2.insert(-now);
    }
    cout<<ans<<endl;
}