#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()
typedef long long LL;
typedef pair<LL,LL> P;
const LL mod=1000000007;
const LL LINF=1LL<<62;
const int INF=1<<30;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

vector<int> G[1<<11];

int dfs(int u,int v,int c,int p){
    int ret = 0;
    for(auto g:G[u]){
        if(g==v) continue;
        ret += dfs(g,u,c+1,p);
    }
    if(c > p) ret++;
    return ret;
}


int main(){
    int n,k;
    cin >> n >> k;
    for (int i = 0; i < n-1; i++) {
        int a,b;cin >> a >> b;
        a--,b--;
        G[a].pb(b);
        G[b].pb(a);
    }
    int ans = INF;
    if(k%2==0){
        for (int i = 0; i < n; i++) {
            int tmp = dfs(i,i,0,k/2);
            ans = min(ans,tmp);
        }
    }
    else{
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < G[i].size(); j++) {
                int tmp = dfs(i,G[i][j],0,k/2)+dfs(G[i][j],i,0,k/2);
                ans = min(ans, tmp);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
