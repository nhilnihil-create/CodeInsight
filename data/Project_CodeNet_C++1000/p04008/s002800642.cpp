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
#define N 100005
#define MXN 200005
vector<int> v[100005];
int ans=0;
int cnt[100005];
int dfs(int x,int k){
  //  printf("%d %d\n",x,sum);
  //  vector<int> v;
    int Max=0;
    for(auto it:v[x]){
        int y=dfs(it,k);
        Max=max(Max,y);
        if(x==1&&y==0)ans--;
    }
    if(Max+1==k&&x!=1){
        ans++;
     //   printf("%d\n",x);
        return 0;
    }
    return Max+1;
    
}
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int p[100005];
    for(int i = 1;i<=n;i++)
        scanf("%d",&p[i]);
    for(int i = 2;i<=n;i++){
        v[p[i]].pb(i);
    }
    if(p[1]!=1)ans++;
    dfs(1,k);
    //for(int i = 1;i<10;i++)
     //   printf("%d ",cnt[i]);
    printf("%d\n",ans);
}
