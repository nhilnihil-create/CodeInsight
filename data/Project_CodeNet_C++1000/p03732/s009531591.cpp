#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(i,n,m) for(int i=(int)(n); i<=(int)(m); i++)
#define RFOR(i,n,m) for(int i=(int)(n); i>=(int)(m); i--)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define RITR(x,c) for(__typeof(c.rbegin()) x=c.rbegin();x!=c.rend();x++)
#define setp(n) fixed << setprecision(n)

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

#define ld long double
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
    int n; ll W; cin>>n>>W;
    vll w(n),v(n);
    vll a,b,c,d;
    rep(i,n) cin>>w[i]>>v[i];
    ll w0 = w[0];
    rep(i,n){
        if (w[i]==w0)   a.pb(v[i]);
        if (w[i]==w0+1) b.pb(v[i]);
        if (w[i]==w0+2) c.pb(v[i]);
        if (w[i]==w0+3) d.pb(v[i]);
    }
    sort(rall(a));
    sort(rall(b));
    sort(rall(c));
    sort(rall(d));
    vll A(a.size()+1,0),B(b.size()+1,0),C(c.size()+1,0),D(d.size()+1,0);
    rep(i,a.size()) A[i+1]=A[i]+a[i];
    rep(i,b.size()) B[i+1]=B[i]+b[i];
    rep(i,c.size()) C[i+1]=C[i]+c[i];
    rep(i,d.size()) D[i+1]=D[i]+d[i];
    ll ans=0;
    rep(i,A.size())rep(j,B.size())rep(k,C.size())rep(l,D.size()){
        ll wsum = i*w0 + j*(w0+1) + k*(w0+2) + l*(w0+3);
        if (wsum<=W) chmax(ans, A[i]+B[j]+C[k]+D[l]);
    }
    cout<<ans<<endl;
    return 0;
}
