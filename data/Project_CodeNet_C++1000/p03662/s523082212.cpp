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
int n,w,b,tag,cnt[100005];vector<int> v[100005],path;
void dfs(int x,int fa){
    path.pb(x);
    if(x==n){
        int len=path.size();
        tag=path[(len+1)/2];
    }
    rap(i,0,v[x].size())
    if(fa!=v[x][i]) {
        dfs(v[x][i],x);
        cnt[x]+=cnt[v[x][i]];
    }
    path.pop_back();
}
int main()
{
    scanf("%d",&n);
    rap(i,1,n){
        int t1,t2;
        scanf("%d%d",&t1,&t2);
        v[t1].pb(t2);v[t2].pb(t1);
    }
    rep(i,1,n) cnt[i]=1;
    dfs(1,0);
    puts(cnt[tag]*2<n?"Fennec":"Snuke");
    return 0;
}