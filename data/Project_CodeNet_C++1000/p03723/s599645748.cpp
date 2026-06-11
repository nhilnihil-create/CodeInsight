#include<bits/stdc++.h>

using namespace std;

int N, x[4];
const int lim = 1e7;

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

for (int i=0; i<3; i++)
    scanf ("%d", &x[i]);
int steps = 0;
while (steps <= lim)
{
    if (x[0] % 2 == 1 || x[1] % 2 == 1 || x[2] % 2 == 1)
        break;
    int sum = 0;
    for (int i=0; i<3; i++)
        x[i] >>= 1, sum += x[i];
    for (int i=0; i<3; i++)
        x[i] = sum - x[i];
    steps ++;
}
if (steps >= lim) steps = -1;
printf ("%d\n", steps);
return 0;
}
