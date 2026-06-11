#include<bits/stdc++.h>
#define N 1009
using namespace std;
const int INF = 0x3f3f3f3f;
typedef long long LL;
 
LL fun(LL n, LL m)
{
    if((m / 2) < n) return  m / 2;
    LL ans = n;
    m = m - n * 2;
    ans = ans + m / 4;
    return ans;
}
 
 
int main()
{
    LL n, m;
    scanf("%lld%lld", &n, &m);
    LL ans = fun(n, m);
    printf("%lld\n", ans);
    return 0;
}

 