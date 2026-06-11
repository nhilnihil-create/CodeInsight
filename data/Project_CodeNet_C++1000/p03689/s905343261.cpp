#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=1005;
int ans[N][N];
int ans1[N][N];
int main()
{
    int n,m,r,c;
    scanf("%d%d%d%d",&n,&m,&r,&c);
    if(n%r==0&&m%c==0){
        puts("No");
        return 0;
    }
    puts("Yes");
    bool flag=false;
    if(n%r==0){
        swap(n,m);
        swap(r,c);
        flag=true;
    }
    for(int j=c;j<=m;j+=c)
        ans[1][j]=999999999;
    for(int i=r;i<=n;i+=r){
        for(int j=c;j<=m;j+=c)
            ans[i][j]=-1000000000,ans[i+1][j]=999999999;
    }
    if(flag){
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                ans1[j][i]=ans[i][j];
            }
        memcpy(ans,ans1,sizeof ans);
        swap(n,m);
        swap(r,c);
    }
    for(int i=1;i<=n;i++,puts(""))
        for(int j=1;j<=m;j++)
            printf("%d ",ans[i][j]);
}
