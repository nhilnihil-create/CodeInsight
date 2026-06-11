#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mit map<int,int>::iterator
#define sit set<int>::iterator
#define itrm(g,x) for(mit g=x.begin();g!=x.end();g++)
#define itrs(g,x) for(sit g=x.begin();g!=x.end();g++)
#define ltype int
#define rep(i,j,k) for(ltype(i)=(j);(i)<=(k);(i)++)
#define rap(i,j,k) for(ltype(i)=(j);(i)<(k);(i)++)
#define per(i,j,k) for(ltype(i)=(j);(i)>=(k);(i)--)
#define pii pair<int,int>
#define fi first
#define se second
#define mpr make_pair
#define pb push_back
#define fastio ios::sync_with_stdio(false)
const int inf=0x3f3f3f3f,mod=1000000007;
const double pi=3.1415926535897932,eps=1e-6;
int n;vector<int> v[100005];int dis[2][100005],w,b;
void dfs(int x,int fa,int h){
    rap(i,0,v[x].size()){
        int to=v[x][i];
        if(to==fa) continue;
        dis[h][to]=dis[h][x]+1;
        dfs(to,x,h);
    }
}
int main()
{
    scanf("%d",&n);
    rap(i,1,n){
        int t1,t2;
        scanf("%d%d",&t1,&t2);
        v[t1].pb(t2);v[t2].pb(t1);
    }
    dfs(1,0,0);
    dfs(n,0,1);
    rep(i,1,n) if(dis[0][i]<=dis[1][i]) b++;else w++;
    if(b>w) puts("Fennec");
    else puts("Snuke");
    return 0;
}