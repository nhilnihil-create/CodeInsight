#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(i,n,m) for(int i=(int)(n); i<=(int)(m); i++)
#define RFOR(i,n,m) for(int i=(int)(n); i>=(int)(m); i--)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define RITR(x,c) for(__typeof(c.rbegin()) x=c.rbegin();x!=c.rend();x++)
#define setp(n) fixed << setprecision(n)

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define pll pair<ll,ll>
#define pi pair<int,int>

#define all(a) (a.begin()),(a.end())
#define rall(a) (a.rbegin()),(a.rend())
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ins insert

using namespace std;

/* Some Libraries */

//-------------------------------------------------

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin>>n;
    vll a(n),b(n),c(n);
    rep(i,n) cin>>a[i];
    rep(i,n) cin>>b[i];
    rep(i,n) cin>>c[i];
    sort(rall(a));
    sort(all(c));
    // Left
    vll dpL(n+1);
    priority_queue<ll,vll,greater<ll> > queL;
    rep(i,n){
        dpL[0]+=a[i];
        queL.push(a[i]);
    }
    rep(i,n){
        dpL[i+1] += dpL[i];
        dpL[i+1] += b[i];
        queL.push(b[i]);
        dpL[i+1] -= queL.top();
        queL.pop();
    }
    // Right
    vll dpR(n+1);
    priority_queue<ll> queR;
    rep(i,n){
        dpR[0]+=c[i];
        queR.push(c[i]);
    }
    rep(i,n){
        dpR[i+1] += dpR[i];
        dpR[i+1] += b[n-i-1];
        queR.push(b[n-i-1]);
        dpR[i+1] -= queR.top();
        queR.pop();
    }
    ll ans=-1e18;
    FOR(i,0,n){
        ll L = dpL[i];
        ll R = dpR[n-i];
        chmax(ans,L-R);
    }
    cout<<ans<<"\n";
    return 0;
}
