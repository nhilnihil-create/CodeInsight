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
int N;
ll A[100000];
vector<int> E[100000];
bool used[100000];
bool dfs(int x){
    used[x]=1;
    if(sz(E[x])==1){
        return true;
    }
    bool t=true;
    ll sum=0;
    ll m=0;
    rep(i,0,sz(E[x])){
        if(used[E[x][i]]==0){
            t&=dfs(E[x][i]);
            sum+=A[E[x][i]];
            m=max(m,A[E[x][i]]);
        }
    }
    if(min(sum-m,sum/2)<sum-A[x]||A[x]>sum||sum>2*A[x]) return false;
    A[x]=2*A[x]-sum;
    return t;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>N;
    rep(i,0,N) cin>>A[i];
    rep(i,0,N-1){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        E[a].pb(b);
        E[b].pb(a);
    }
    rep(i,0,N){
        if(sz(E[i])>1){
            if(dfs(i)&&A[i]==0){
                cout <<"YES"<<"\n";
            }
            else cout <<"NO"<<"\n";
            return 0;
        }
    }
    if(A[0]==A[1]) cout <<"YES"<<"\n";
    else cout <<"NO"<<"\n";
}