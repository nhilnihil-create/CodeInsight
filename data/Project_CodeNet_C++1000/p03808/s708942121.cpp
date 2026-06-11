//#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 500;
const int mod = 1e8 + 7;
const double pi = acos(-1);
const int inf = 1e9;
const double eps = 1e-7;
int n,k;
ll a[N],cha[N];
ll sum;
int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", a + i), sum += a[i];
    if (sum % ((ll)n * (n + 1) / 2))
    {
        puts("NO");
        return 0;
    }
    sum /= ((ll)n * (n + 1) / 2);
    for (int i = 1; i < n; ++i)
        cha[i] = a[i + 1] - a[i];
    cha[n] = a[1] - a[n];
    int f = 1;
    for (int i = 1; i <= n; ++i)
        if (cha[i] > sum || (cha[i] - sum) % n)
            f = 0;
    if (f)
        puts("YES");
    else
        puts("NO");
    return 0;
}