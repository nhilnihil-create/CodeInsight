#include <cstdio>
#include <cstdio>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 200007;
const int M = 15005;
const int offset = 7500;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
const double eps = 1e-20;
LL n,m;
LL ans[105];
int main()
{
    while (~scanf("%lld",&n))
    {
        LL tmp = n/50;
        LL tm = n%50;
        for (int i=0;i<50;i++)
            ans[i] = i + tmp ;
        for (int i=49; i>=0 && tm>0;i--)
        {
            ans[i]++;
            tm--;
            // cout<<i<<" "<<ans[i]<<endl;
        }
        printf("50\n");
        for (int i=0;i<50;i++)
        {
            printf("%lld", ans[i]);
            if (i<49)
                printf(" ");
            else
                printf("\n");
        }
        
    }
    return 0;
}

/*


*/