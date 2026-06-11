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
int n,col[100005],c1,c2;vector<int> v[100005],cpath,path;
void dfs(int x,int fa){
    cpath.pb(x);
    if(x==n) path=cpath;
    rap(i,0,v[x].size())
    if(fa!=v[x][i])
    dfs(v[x][i],x);
    cpath.pop_back();
}
void fill(int x,int fa){
    rap(i,0,v[x].size()){
        int to=v[x][i];
        if(to==fa||col[to]) continue;
        col[to]=col[x];
        fill(to,x);
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
    dfs(1,0);
    int len=path.size();
    rap(i,0,len)
    if(i*2<len) col[path[i]]=1;else col[path[i]]=2;
    rap(i,0,len) fill(path[i],0);
    rep(i,1,n) if(col[i]==1) c1++;else c2++;
    //rep(i,1,n) printf("%d ",col[i]);
    puts(c1>c2?"Fennec":"Snuke");
    return 0;
}