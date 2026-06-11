#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N],vis[N];
int main()
{
    int n,x;scanf("%d%d",&n,&x);
    if(x==1||x==2*n-1){printf("No\n");return 0;}
    printf("Yes\n");
    if(n==2){printf("1\n2\n3\n");return 0;}
    if(x==2*n-2)a[n-1]=x-2,a[n]=x,a[n+1]=x+1,a[n+2]=x-1,vis[x-2]=1;
    else a[n-1]=x+2,a[n]=x,a[n+1]=x-1,a[n+2]=x+1,vis[x+2]=1;
    vis[x]=vis[x+1]=vis[x-1]=1;
    int k=1;
    for(int i=1;i<=2*n-1;i++)
    {
        if(a[i])continue;
        while(vis[k])k++;a[i]=k;vis[k]=1;
    }
    for(int i=1;i<=2*n-1;i++)printf("%d\n",a[i]);
}
