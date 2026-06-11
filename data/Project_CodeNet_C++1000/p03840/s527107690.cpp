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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll a,b,c,d,e,f,g;
    cin>>a>>b>>c>>d>>e>>f>>g;
    ll ans=0;
    ans+=a/2*2;
    ans+=d/2*2;
    ans+=e/2*2;
    ans+=b*1;
    ll res=3;
    a--;
    d--;
    e--;
    res+=a/2*2;
    res+=d/2*2;
    res+=e/2*2;
    res+=b*1;
    if(a<0||d<0||e<0) res=0;
    cout <<max(ans,res)<<"\n";
}