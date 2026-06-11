#include<bits/stdc++.h>
#define maxn 500
#define rt register int
using namespace std;
int n,m;
int a[maxn][maxn],vis[maxn],cnt[maxn];
inline int min(int a,int b){
	return a<b?a:b;
}
inline int read()
{
    int x=0,f=0;char s=getchar();
    while(!isdigit(s))f|=s=='-',s=getchar();
    while( isdigit(s))x=(x<<1)+(x<<3)+s-48,s=getchar();
    return !f?x:-x;
}
inline void print(int x)
{
    if(x/10>0)print(x/10);
    putchar(x%10+'0');
}
int main(){
    n=read();m=read();
    for (rt i=1;i<=n;i++)
        for (rt j=1;j<=m;j++)
            a[i][j]=read();
    int ans=n;
    for (rt i=1;i<=m;i++){
        memset(cnt,0,sizeof(cnt));
        for (rt j=1;j<=n;j++)
            for (rt k=1;k<=m;k++)
                if (!vis[a[j][k]]){
                    cnt[a[j][k]]++;
                    break;
                }
        int s,sum=0;
        for (rt j=1;j<=m;j++)
            if (sum<cnt[j])
                s=j,sum=cnt[j];
        vis[s]=1;
        ans=min(ans,sum);
    }
    print(ans);
    return 0;
}