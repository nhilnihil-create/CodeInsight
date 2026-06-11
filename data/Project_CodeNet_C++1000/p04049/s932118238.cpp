#include <stdio.h>

int n,k;
struct eee{
    int to,next;
}edge[4010];
int box[2010];
int flag[2010];
int ee1[2010],ee2[2010];
int fin(int now ,int dis ,int maxdis)
{
    flag[now]=1;
    if (maxdis==dis){
        return 0;
    }
    for (int temp=box[now];temp>0;temp=edge[temp].next)
        if(flag[ edge[temp].to ]==0) fin(edge[temp].to,dis+1,maxdis);
}

int main1()
{
    int ans=n;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++) flag[j]=0;
        flag[i]=1;
        fin(i,0,k/2);
        int temp=0;
        for (int j=1;j<=n;j++) temp+=flag[j];
        if (n-temp<ans) ans=n-temp;
    }
    printf("%d\n",ans);
}
int main2()
{
    int ans=n;
    for (int i=1;i<n;i++)
    {
        for (int j=1;j<=n;j++) flag[j]=0;
        flag[ee1[i]]=flag[ee2[i]]=1;
        fin(ee1[i],0,(k-1)/2 );fin(ee2[i],0,(k-1)/2);
        int temp=0;
        for (int j=1;j<=n;j++) temp+=flag[j];
        if (n-temp<ans) ans=n-temp;
    }
    printf("%d\n",ans);
}

int main()
{
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++) box[i]=-1;
    for (int i=1;i<n;i++)
    {
        int a,b;scanf("%d%d",&a,&b);
        ee1[i]=a;ee2[i]=b;
        edge[i*2-1].to=b;edge[i*2-1].next=box[a];box[a]=i*2-1;
        edge[i*2].to=a;edge[i*2].next=box[b];box[b]=i*2;
    }

    if (k%2==0) main1();else main2();
    return 0;
}
