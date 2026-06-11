#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define All(x) x.begin(),x.end()
#define gett(x) scanf("%d",&x);
#define Add(x,y) x=(x+y)%p
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
 
const int N=2e5+99,K=103;

int n,m,u,v,p,c,t[2],h[N],mark[N];
ll ans;
vector<int> g[N];

void dfs(int x){
    mark[x]=1;
    f(i,0,g[x].size())
        if(mark[g[x][i]] && h[x]==h[g[x][i]])
            c=1;
    f(i,0,g[x].size())
        if(!mark[g[x][i]])
            h[g[x][i]]=h[x]^1,dfs(g[x][i]);
}
int main(){
    cin>>n>>m;
    p=n;
    f(i,0,m){
        Gett(u,v);
        g[u].pb(v);
        g[v].pb(u);
    }
    f(i,1,n+1)
        if(!mark[i]){
            if(sz(g[i])){
                c=0;
                dfs(i);
                t[c]++;
            }
            else ans+=p*2-1,p--;
        }
    ans+=1ll*(t[0]+t[1])*(t[0]+t[1])+1ll*t[0]*t[0];
    cout<<ans;
}