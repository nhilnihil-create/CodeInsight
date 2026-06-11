#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 200000;
LL ai[N], bi[N], all, ans;
string opt;
int n, m;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++ i)
    {
        int a;
        if (i == 1) opt = "+"; else cin >> opt;
        cin >> a; all += a;
        if (opt == "-") ai[++ m] = a;
        else bi[m] += a;
    }
    if (m == 0) ans = all;
    for (int i = 1; i <= m; ++ i)
    {
        all -= (ai[i] + bi[i]);
        ans = max(ans, all - ai[i] - bi[i]);
        all += (-ai[i] + bi[i]);
    }
    cout << ans << endl;
}
