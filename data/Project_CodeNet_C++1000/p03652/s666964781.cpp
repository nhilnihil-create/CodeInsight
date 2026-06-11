#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define N 301
int n,m;
int a[N][N];
int num[N];
bool v[N];
int ans;
int main(){
    scanf("%d%d",&n,&m);
    int s;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j)
            scanf("%d",&a[i][j]);
        int b=a[i][1];
        if(++num[b]>ans){
            ans=num[b];
            s=b;
        }
    }
    for(int i=1;i<m;++i){
        memset(num,0,sizeof num);
        v[s]=1;
        int tans=0;
        for(int j=1;j<=n;++j){
            for(int k=1;k<=m;++k){
                int b=a[j][k];
                if(!v[b]){
                    if(++num[b]>tans){
                        tans=num[b];
                        s=b;
                    }
                    break;
                }
            }
        }
        ans=min(ans,tans);
    }
    printf("%d",ans);
    return 0;
}