#include<bits/stdc++.h>

using namespace std;

int N, M, a[102];
vector < int > sol;

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
for (int i=1; i<=M; i++)
    scanf ("%d", &a[i]);
for (int i=2; i<M; i++)
    if (a[i] % 2 == 1)
    {
        if (a[1] % 2 == 0) swap (a[1], a[i]);
        else
        if (a[M] % 2 == 0) swap (a[M], a[i]);
    }
int oddCount = 0;
for (int i=1; i<=M; i++)
    oddCount += a[i] % 2;
if (oddCount > 2)
{
    printf ("Impossible\n");
    return 0;
}
if (M == 1)
{
    if (N == 1) printf ("1\n1\n1\n");
    else printf ("%d\n2\n%d %d\n", N, 1, N - 1);
    return 0;
}
for (int i=1; i<=M; i++)
{
    printf ("%d ", a[i]);
    int curr = (a[i] + (i == 1) - (i == M));
    if (curr > 0) sol.push_back (curr);
}
printf ("\n%d\n", sol.size ());
for (auto it = sol.begin (); it != sol.end (); it ++)
    printf ("%d ", *it);
printf ("\n");
return 0;
}
