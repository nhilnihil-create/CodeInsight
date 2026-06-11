#include <bits/stdc++.h>
#define rep(i, a, b) for(ll i = ll(a); i < ll(b); i++)
#define rer(i, a, b) for(ll i = ll(a) - 1; i >= ll(b); i--)
#define sz(v) (int)(v).size()
#define pb push_back
#define sc second
#define fr first
#define sor(v) sort(v.begin(),v.end())
#define rev(s) reverse(s.begin(),s.end())
#define lb(vec,a) lower_bound(vec.begin(),vec.end(),a)
#define ub(vec,a) upper_bound(vec.begin(),vec.end(),a)
#define uniq(vec) vec.erase(unique(vec.begin(),vec.end()),vec.end())
using namespace std;
typedef long long int ll;
typedef pair <int, int> P;

const ll MOD=1000000007;
ll N,K;
ll a[100000];
ll s[100001], p[100001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>K;
    rep(i,0,N) cin>>a[i];
    rep(i,0,N){
        s[i+1]=s[i]+a[i];
        p[i+1]=p[i]+(a[i]>0?a[i]:0);
    }
    ll ans=0;
    rep(i,0,N-K+1){
        ans=max(ans,s[i+K]-s[i]+p[i]+p[N]-p[i+K]);
        ans=max(ans,p[i]+p[N]-p[i+K]);
    }
    cout <<ans<<"\n";
}