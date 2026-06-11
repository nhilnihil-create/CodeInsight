#include<bits/stdc++.h>

using namespace std;

int N;

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=N; i>=1; i--)
    if (1LL * (i - 1) * i / 2 < N) N -= i, printf ("%d\n", i);
return 0;
}
