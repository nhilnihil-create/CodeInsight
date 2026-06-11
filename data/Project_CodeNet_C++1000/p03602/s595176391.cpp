#include <cstdio>
#define repu(i,x,y) for (int i=x; i<=y; ++i)
using namespace std;

typedef long long LL;
int n,d[310][310];
LL ans;

int main()
{
    scanf("%d",&n);
    repu(i,1,n)
        repu(j,1,n)
            scanf("%d",&d[i][j]);
    repu(i,1,n)
        repu(j,i+1,n)
        {
            bool flag=0;
            repu(k,1,n)
                if (i!=k && j!=k)
                {
                    flag|=d[i][j]==d[i][k]+d[j][k];
                    if (d[i][k]+d[j][k]<d[i][j])
                    {
                        puts("-1");
                        return 0;
                    }
                }
            if (!flag)
                ans+=d[i][j];
        }
    printf("%lld\n",ans);
    return 0;
}