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
ll N, K;
ll a[100000];
vector<int> E[100000];
int h[100000];
ll ans=0;
void dfs(int x){
    if(sz(E[x])==0){
        h[x]=0;
        return;
    }
    for(auto i: E[x]){
        dfs(i);
        if(h[i]==K-1&&x!=0){
            ans++;
            h[i]=-1;
        }
    }
    for(auto i: E[x]){
        h[x]=max(h[x], h[i]+1);
    }
    if(h[x]==K&&x!=0){
        ans++;
        h[x]=0;
    }
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>K;
    rep(i,0,N){
        cin>>a[i];
        if(i>0){
            E[a[i]-1].pb(i);
        }
    }
    if(a[0]!=1) ans++;
    rep(i,0,N) h[i]=-2;
    dfs(0);
    cout <<ans<<"\n";
}