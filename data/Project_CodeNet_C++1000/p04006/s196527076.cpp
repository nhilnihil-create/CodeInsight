/* 
    
*/ 
#include <bits/stdc++.h>
#define md(x, y)  (x + y) / 2
#define ls(x)      x << 1
#define rs(x)      x << 1 | 1
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const double PI = acos(-1.0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 10;
ll n, a[MAXN], x;
ll cost[MAXN];//对于最小花费是自己的，放在最后
ll dp[MAXN][50];                        
void init()
{
    for(int i = 1; i <= n; i++)
        dp[i][0] = a[i];
    int nlog = (int)log2(n);
    for(int j = 1; j <= nlog; j++)
        for(int i = 1; i <= n; i++)
            if((i + (1 << j) - 1) <= n)
                dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
}
ll rmq(int s, int e)
{
    if(s > e)   return 1e18;
    int nlog = (int)log2(e - s + 1);
    return min(dp[s][nlog], dp[e - (1 << nlog) + 1][nlog]);
}
int main()
{
    cin >> n >> x;
    for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    init();
    ll ans = 1e18;
    for(int k = 0; k < n; k++)  //枚举次数
    {
        for(int i = 1; i <= n; i++)
        {
            cost[i] = a[i];
            if(i > 1 && k)
            {
                int L = max(1, i - k);
                int R = i - 1;
                cost[i] = min(cost[i], rmq(L, R));
                if(i - k < 1)
                {
                    
                    int L = n + 1 - (k - (i - 1));
                    int R = n;
                    //printf("2.L = %d, R = %d\n", L, R);
                    cost[i] = min(cost[i], rmq(L, R));
                }
            }
            else if(k)
            {
                int L = n + 1 - k;
                int R = n;
                //printf("L = %d, R = %d\n", L, R);
                cost[i] = min(cost[i], rmq(L, R));
            }
            //printf("cost[%d] = %d\n", i, cost[i]);
        }
        ll sum = k * x;
        for(int i = 1; i <= n; i++) sum += cost[i];
        ans = min(sum, ans);
    }
    printf("%lld\n", ans);
    return 0;
}