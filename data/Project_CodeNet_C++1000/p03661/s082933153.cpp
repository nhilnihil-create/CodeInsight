#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define INF 0x3f3f3f3f3f3f3f3f
long long sum[MAXN];
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%lld", &sum[i]);
        if(i > 0)
            sum[i] += sum[i - 1];
    }
    long long min = INF;
    for(int i = 0; i < n - 1; i++)
    {
        long long cha = abs(sum[n - 1] - 2 * sum[i]);
        if(cha < min)
            min = cha;
    }
    cout << min << endl;
    return 0;
}
