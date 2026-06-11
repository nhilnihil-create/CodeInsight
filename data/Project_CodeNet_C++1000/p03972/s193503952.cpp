#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define debug(n,v) cout<<#v<<":";for(int i=0;i<n;i++)cout<<v[i]<<" ";cout<<endl; 
#define INF 1000000000
#define mod 1000000007
typedef long long ll;
const ll LINF = 1001002003004005006ll;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main(){
    int w,h;
    cin>>w>>h;
    ll ans=0;
    vector<ll> p(w);
    rep(i,w){
        cin>>p[i];
        ans+=p[i];
    }
    vector<ll> q(h);
    rep(i,h){
        cin>>q[i];
        ans+=q[i];
    }

    sort(ALL(p));
    sort(ALL(q));

    vector<ll> sump(w+1,0);
    vector<ll> sumq(h+1,0);

    rep(i,w){
        sump[i+1]=sump[i]+p[i];
    }
    rep(i,h){
        sumq[i+1]=sumq[i]+q[i];
    }

    //w=p,h=q
    rep(i,h){
        int idx=(lower_bound(ALL(p),q[i])-p.begin());
        idx--;
        ans+=sump[idx+1];
        ans+=q[i]*(w-idx-1);
    }
    cout<<ans<<endl;
    return 0;
}
