#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define inf 0x3f3f3f3f
#define met(a, x) memset(a,x,sizeof(a))
#define mp make_pair;

using namespace std;
const int mod = 19e+7;
const int N = 1e5 + 10;
const int M = 1e6 + 10;
int m,n;
struct rec{
    int y,nex;
}edge[2*N];
int head[N],q1[N],q2[N],q3[N];
int val[N],maxd[N];
int cnt=0;
void add(int u,int v){
    edge[++cnt].y=v;
    edge[cnt].nex=head[u];
    head[u]=cnt;
}
void dfs(int u,int d,int x){
    if(maxd[u]>=d)
        return ;
    if(!val[u])
        val[u]=x;
    if(d==0)
        return;
    maxd[u]=d;
    for(int i=head[u];i;i=edge[i].nex){
        dfs(edge[i].y,d-1,x);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        add(a,b);
        add(b,a);
    }
    int q;
    cin>>q;
    met(maxd,-1);
    met(val,0);
    for(int i=1;i<=q;i++)
        cin>>q1[i]>>q2[i]>>q3[i];
    for(int i=q;i>=1;i--){
        dfs(q1[i],q2[i],q3[i]);
    }
    for(int i=1;i<=n;i++){
        cout<<val[i]<<endl;
    }
    return 0;
}