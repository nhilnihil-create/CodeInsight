#include<bits/stdc++.h>

using namespace std;

int N, x[100009];
const int mod = 1e9 + 7;

int mul (int x, int y) {return 1LL * x * y % mod;}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N), x[0] = -1;
for (int i=1; i<=N; i++)
    scanf ("%d", &x[i]), x[i] = min (x[i], x[i - 1] + 2);
int i = 1;
int sz = 1, ans = 1;
while (sz)
{
    while (i <= N && x[i] >= x[i - 1] + 2)
        x[i] = x[i - 1] + 2, i ++, sz ++;
    i --, sz --;
    if (i == N)
    {
        while (sz)
            ans = mul (ans, sz), sz --;
        break;
    }
    else
    {
        ans = mul (ans, sz + 1);
        x[i + 1] = x[i], x[i] -= 2, i ++;
    }
}
printf ("%d\n", ans);
return 0;
}
