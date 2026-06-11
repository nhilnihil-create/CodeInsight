#include<bits/stdc++.h>

using namespace std;

int N, a[100009], frst[100009];
long long s[100009];
char sg[100009];

long long sum (int i, int j)
{
    if (j > N) j = N;
    if (i > j) return 0;
    return s[j] - s[i - 1];
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
scanf ("%d", &a[1]), s[1] = a[1];
for (int i=2; i<=N; i++)
    scanf (" %c %d", &sg[i], &a[i]), s[i] = s[i - 1] + a[i];
frst[N + 1] = N + 1;
for (int i=N; i>=2; i--)
    if (sg[i] == '-') frst[i] = i;
    else frst[i] = frst[i + 1];
long long curr = a[1], ans = -1LL << 50;
for (int i=2; i<=N; i++)
{
    if (sg[i] == '-')
    {
        if (i == 2)
            i = 2;
        ///try putting a bracket right before a[i] and after its preceding minus
        long long curr2 = curr + sum (frst[i + 1], N) - sum (i, frst[i + 1] - 1);
        if (curr2 > ans) ans = curr2;
        ///
        curr -= a[i];
    }
    else curr += a[i];
}
if (curr > ans) ans = curr;
printf ("%lld\n", ans);
return 0;
}
