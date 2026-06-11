#include<bits/stdc++.h>
#pragma optimizer(O2)
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
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
//#define MXN 300000
#define N 100005
vector<int> v[2005];
int dfs(int x,int f,int k){
    if(k==0)return 1;
    int res=1;
    for(auto it:v[x]){
        if(it!=f){
            res=res+dfs(it,x,k-1);
        }
    }
    return res;
}
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    pii p[2005];
    for(int i = 1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
        p[i]=mp(x,y);
    }
    if(k&1){
        int ans=0;
        for(int i = 1;i<n;i++){
            ans=max(ans,dfs(p[i].x,p[i].y,k/2)+dfs(p[i].y,p[i].x,k/2));
        }
        printf("%d\n",n-ans);
    }
    else{
        int ans=0;
        for(int i = 1;i<=n;i++){
           ans=max(ans,dfs(i,0,k/2));
        }
        printf("%d\n",n-ans);
    }
}