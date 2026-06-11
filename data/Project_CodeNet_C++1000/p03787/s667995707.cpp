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
ll N,M;
const int MAX_V=100000;
vector <int> G[MAX_V];
int color[MAX_V];
//頂点を１と−１で塗る
bool dfs(int v,int c){
    color[v] = c;
    bool t=true;
    rep(i, 0, G[v].size()){
        //隣接している頂点が同じ色ならfalse
        if (color[G[v][i]] == c) t=false;
        //隣接している頂点がまだ塗られていないなら-cで塗る
        if (color[G[v][i]] == 0 && !dfs(G[v][i], -c)) t=false;
    }
    //すべて塗れたらtrue
    return t;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>M;
    rep(i,0,M){
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        G[u].pb(v);
        G[v].pb(u);
    }
    ll s=0,t=0,k=0;
    rep(i,0,N){
        if(color[i]==0){
            if(sz(G[i])==0) k++;
            else{
                if(dfs(i,1)){
                        s++;
                        t++;
                }
                else{
                    t++;
                }
            }
        }
    }
    cout <<N*N-(N-k)*(N-k)+t*t+s*s<<"\n";
}