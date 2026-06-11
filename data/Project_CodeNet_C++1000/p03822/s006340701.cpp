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
ll N;
ll a[100000];
vector<int> E[100000];
int ans[100000];
void dfs(int x){
    if(sz(E[x])==0){
        ans[x]=0;
        return;
    }
    vector<int> v;
    rep(i,0,sz(E[x])){
        dfs(E[x][i]);
        v.pb(ans[E[x][i]]);
    }
    sor(v);
    rep(i,0,sz(v)){
        v[i]+=sz(v)-1-i;
    }
    ans[x]=*max_element(v.begin(), v.end())+1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>N;
    rep(i,1,N){
        ll a;
        cin>>a;
        a--;
        E[a].pb(i);
    }
    dfs(0);
    cout <<ans[0]<<"\n";
}