#include <cstdio>
#include <algorithm>

int n,x[200005],l,q,Next[200005][21];

int main()
{
    //freopen("in.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",&x[i]);
    scanf("%d%d",&l,&q);
    for(int i=n,j=n;i>=1;--i)
    {
        while(x[j]-x[i]>l)--j;
        Next[i][0]=j;
        for(int k=1;k<=20;++k)Next[i][k]=Next[Next[i][k-1]][k-1];
    }
    for(int a,b;q--;)
    {
        scanf("%d%d",&a,&b);
        if(a>b)std::swap(a,b);
        if(a==b){puts("0");continue;}
        int Ans=0;
        for(int i=20;i>=0;--i)
            if(Next[a][i]<b)
                Ans+=1<<i,a=Next[a][i];
        printf("%d\n",Ans+1);
    }
    return 0;
}