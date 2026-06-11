#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define KK 500
#define MXN 200005
vector<int> v[100005];
int vis[100005][15];
int color[100005];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    int q;
    scanf("%d",&q);
    vector<tuple<int,int,int> > qu;
    for(int i = 0;i<q;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        qu.push_back(make_tuple(a,b,c));
    }
    reverse(qu.begin(),qu.end());
    for(auto it:qu){
        int vv,d,c;
        tie(vv,d,c)=it;
        queue<pii> q;
        q.push(mp(vv,d));
        vis[vv][d]=1;
        if(color[vv]==0)color[vv]=c;
        while(!q.empty()){
            pii p=q.front();
            q.pop();
            if(p.y==0)continue;
            for(auto it:v[p.x]){
                if(!vis[it][p.y-1]){
                    vis[it][p.y-1]=1;
                    q.push(mp(it,p.y-1));
                    if(color[it]==0)
                        color[it]=c;
                }
            }
        }
    }
    for(int i = 1;i<=n;i++)
        printf("%d\n",color[i]);
}