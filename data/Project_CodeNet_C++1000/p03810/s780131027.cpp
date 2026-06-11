#include<bits/stdc++.h>

using namespace std;

int N, a[100009];

void Ans (int win)
{
    if (win == 1) printf ("First\n");
    else printf ("Second\n");
    exit (0);
}

int gcd (int a, int b)
{
    int r;
    while (b)
        r = a % b, a = b, b = r;
    return a;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]);
int mv = 1;
while (1)
{
    int cntEven = 0, cntOdd = 0;
    for (int i=1; i<=N; i++)
        if (a[i] > 1)
            cntOdd += (a[i] & 1), cntEven += ((a[i] & 1) ^ 1);
    if (cntEven % 2 == 1) Ans (mv);
    if (cntEven == N - 1 && cntOdd == 1)
    {
        for (int i=1; i<=N; i++)
            if (a[i] & 1)
            {
                a[i] --;
                break;
            }
        int g = a[1];
        for (int i=2; i<=N; i++)
            g = gcd (g, a[i]);
        for (int i=1; i<=N; i++)
            a[i] /= g;
    }
    else Ans (3 - mv);
    mv = 3 - mv;
}
return 0;
}
