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
LL val[100005];
LL Max[100005];
LL Min[100005];
int ok=1;
void dfs(int x,int f){
    if(v[x].size()==1&&f!=0){
        Min[x]=Max[x]=val[x];
        //Min[x]=val[x]&1;
        return ;
    }
    vector<pll> tmp;
    for(auto it:v[x]){
        if(it!=f){
            dfs(it,x);
            tmp.pb(mp(Max[it],Min[it]));
        }
    }
    for(auto& it:tmp){
        if(it.x%2==val[x]%2){
            it.x=min(it.x,val[x]);
        }
        else{
            it.x=min(it.x,val[x]-1);
        }
        if(it.x<it.y)ok=0;
    }
    LL a=0,b=0;
    for(auto &it:tmp){
        a+=it.x;
        b+=it.y;
    }
    a=2*val[x]-a;
    b=2*val[x]-b;
    if(a<0){
        if(a%2)a=1;
        else a=0;
    }
    if(b%2==val[x]%2)
        b=min(b,val[x]);
    else    
        b=min(b,val[x]-1);
    if(a>b){
        ok=0;
    }
    Min[x]=a;
    Max[x]=b;
   // printf("%d %d %d\n",x,Max[x],Min[x]);
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
        scanf("%lld",&val[i]);
    for(int i = 1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    if(n==2){
        if(val[1]==val[2]){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    else{
        for(int i=1;i<=n;i++){
            if(v[i].size()!=1){
                dfs(i,0);
                if(Min[i]!=0){
                    ok=0;
                }
                break;
            }
        }
        if(ok){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
}