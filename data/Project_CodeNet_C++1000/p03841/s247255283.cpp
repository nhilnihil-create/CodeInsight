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
int main(){
    int n;
    scanf("%d",&n);
    int ans[300000];
    MEM(ans);
    int now=1;
    pii p[505];
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        p[i]=mp(x,i);
    }
    sort(p+1,p+n+1);
    for(int i=1;i<=n;i++){
       /* if(ans[p[i].x]!=0){
            printf("No\n");
            return 0;
        }*/
        ans[p[i].x]=p[i].y;
        for(int j=1;j<p[i].y;j++){
            while(ans[now]!=0)now++;
            ans[now]=p[i].y;
        }
        if(now>p[i].x){
            printf("No\n");
            return 0;
        }
    }
    queue<int> q;
    now=1;
    for(int i = 1;i<=n*n;i++){
        if(ans[i]==0){
            if(q.empty()){
                printf("No\n");
                return 0;
            }
           // printf("%d\n",q.front());
            ans[i]=q.front();
            q.pop();
        }
        while(p[now].x<=i&&now!=n+1){
            for(int j=p[now].y+1;j<=n;j++){
                q.push(p[now].y);
                //printf("%d\n",p[now].y);
            }
            now++;
        }
    }
    printf("Yes\n");
    for(int i = 1;i<=n*n;i++)
        printf("%d ",ans[i]);
    printf("\n");
}
/*
1441152
*/