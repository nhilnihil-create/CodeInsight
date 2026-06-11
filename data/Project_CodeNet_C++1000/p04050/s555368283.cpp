# include <cstdio>
# include <iostream>
# define R register int

using namespace std;

const int maxn=100005;
int n,m,cnt;
int a[maxn],b[maxn];

int main()
{
    scanf("%d%d",&n,&m);
    for (R i=1;i<=m;++i)
    {
        scanf("%d",&a[i]);
        if(a[i]&1) cnt++;
    }
    if(m==1)
    {
    	if(a[1]==1) printf("1\n1\n1\n");
		else printf("%d\n2\n%d %d\n",a[1],a[1]-1,1);
		return 0;
	}
    if(cnt>2) puts("Impossible");
    else
    {
        int p=1;
		for (R i=1;i<=m;++i)
		{
			if((a[i]%2)&&p==1) swap(a[i],a[1]),p++;
			else if((a[i]%2)&&p==2) swap(a[i],a[m]);
		}
        for (R i=1;i<=m;++i)
        	printf("%d ",a[i]);
        printf("\n");
        printf("%d\n",m-(a[m]==1));
        printf("%d ",a[1]+1);
        for (R i=2;i<m;++i)
        	printf("%d ",a[i]);
        if(a[m]>1) printf("%d ",a[m]-1);
    }
    return 0;
}