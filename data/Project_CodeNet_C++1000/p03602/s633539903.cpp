# include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL dis[303][303];
int main()
{
    LL sum = 0;
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j) scanf("%lld",&dis[i][j]);
    for(int i=1; i<n; ++i)
    {
        for(int j=i+1; j<=n; ++j)
        {
            LL imin = 0x3f3f3f3f3f3f3f3f;
            for(int k=1; k<=n; ++k)
            {
                if(k==i||k==j) continue;
                if(dis[i][k]+dis[k][j] < dis[i][j]) return 0*puts("-1");
                imin = min(imin, dis[i][k]+dis[k][j]);
            }
            if(imin > dis[i][j]) sum += dis[i][j];
        }
    }
    printf("%lld\n",sum);
    return 0;
}
