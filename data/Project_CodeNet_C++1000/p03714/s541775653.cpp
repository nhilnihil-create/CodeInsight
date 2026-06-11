#include<bits/stdc++.h>
using namespace std;
const long long llINF = 9223372036854775807;
const int INF = 2147483647;
const int maxn = 3e5 + 7;
const int maxm = 2e5 + 7;
const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const double eps = 1e-10;
long long a[maxn];
int n;
multiset<long long> s;
priority_queue<long long> Q;
long long sum;
long long ans = -llINF;
long long pre[maxn], suffix[maxn];
int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i = 1; i <= 3 * n; i++)
        scanf("%lld", &a[i]);

    for (int i = 1; i <= n * 2; i++) //最大的
    {
        s.insert(a[i]);
        sum += a[i];
        if (i > n)
        {
            sum -= *s.begin();
            s.erase(s.begin());
        }
        pre[i] = sum; //删到i位置
    }

    sum = 0;

    for (int i = n * 3; i >= n + 1; i--) //最小的
    {
        Q.push(a[i]);
        sum += a[i];
        if (i <= 2*n)
        {
            sum -= Q.top();
            Q.pop();
        }
        suffix[i] = sum;
    }

    for (int i = n; i <= n * 2; i++)
        ans = max(ans, pre[i] - suffix[i + 1]);

    printf("%lld\n", ans);

    return 0;
}