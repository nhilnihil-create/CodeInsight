#include<bits/stdc++.h>

using namespace std;

int sg[1000009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int N, M, x, y;
scanf ("%d %d", &N, &M);
while (M --)
    scanf ("%d %d", &x, &y),
    sg[x] ^= 1, sg[y] ^= 1;
bool ok = 1;
for (int i=1; i<=N; i++)
    if (sg[i])
        ok = 0;
if (ok) printf ("YES\n");
else printf ("NO\n");
return 0;
}
