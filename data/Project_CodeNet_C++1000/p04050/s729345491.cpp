#include <cstdio>
#include <algorithm>
#define repu(i,x,y) for (int i=x; i<=y; ++i)
using namespace std;

int n,m,a[110];

int main()
{
    scanf("%d%d",&n,&m);
    repu(i,1,m)
        scanf("%d",&a[i]);
    repu(i,2,m-1)
        if (a[i]&1)
            if (!(a[1]&1))
                swap(a[1],a[i]);
            else
                if (!(a[m]&1))
                    swap(a[m],a[i]);
                else
                {
                    puts("Impossible");
                    return 0;
                }
    repu(i,1,m)
        printf("%d ",a[i]);
    if (m==1)
    {
        if (a[1]==1)
            printf("\n1\n1\n");
        else
            printf("\n2\n1 %d\n",a[1]-1);
        return 0;
    }
    printf("\n%d\n",m-(a[1]==1));
    if (a[1]>1)
        printf("%d ",a[1]-1);
    repu(i,2,m-1)
        printf("%d ",a[i]);
    printf("%d\n",a[m]+1);
    return 0;
}