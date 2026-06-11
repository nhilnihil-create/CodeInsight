#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1e5+500;
int tmp[N],w[N],odd[N],p[N],n,m;
int main()
{
    scanf("%d%d",&n,&m);int cnt=0;
    for(int i=1;i<=m;i++)
    {
        scanf("%d",w+i);
        if(w[i]&1)odd[++cnt]=w[i],p[i]=1;
    }
    if(m==1){}
    if(cnt>=3){puts("Impossible");return 0;}
    int tn=0;for(int i=1;i<=m;i++)if(!p[i])tmp[++tn]=w[i];
    if(cnt==1)
    {
        printf("%d ",odd[1]);
        for(int i=1;i<=tn;i++)printf("%d ",tmp[i]);puts("");
        if(m==1)
        {
            if(n==1)printf("%d\n%d",1,1);
            else printf("%d\n%d %d\n",2,odd[1]-1,1);
            return 0;
        }
        printf("%d\n",m);
        printf("%d ",odd[1]+1);
        for(int i=1;i<tn;i++)printf("%d ",tmp[i]);
        if(tn)printf("%d\n",tmp[tn]-1);
        return 0;
    }
    if(!cnt)
    {
        for(int i=1;i<=tn;i++)printf("%d ",tmp[i]);puts("");
        if(m==1){printf("%d\n",2);printf("%d %d\n",1,tmp[1]-1);return 0;}
        printf("%d\n",m);
        printf("%d ",tmp[1]+1);
        for(int i=2;i<tn;i++)printf("%d ",tmp[i]);
        printf("%d\n",tmp[tn]-1);
        return 0;
    }
    printf("%d ",odd[1]);
    for(int i=1;i<=tn;i++)printf("%d ",tmp[i]);
    printf("%d\n",odd[2]);
    if(odd[2]==1)printf("%d\n",m-1);else printf("%d\n",m);
    printf("%d ",odd[1]+1);
    for(int i=1;i<=tn;i++)printf("%d ",tmp[i]);
    if(odd[2]!=1)printf("%d\n",odd[2]-1);
}