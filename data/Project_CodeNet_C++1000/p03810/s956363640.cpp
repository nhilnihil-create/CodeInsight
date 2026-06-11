# include <bits/stdc++.h>
 
using namespace std;
 
const int  N = 1e5 + 5;
 
int n, ar[N];
 
int calc (int player = 1)
{
    int cn = 0, in, gcd;
    for (int i = 1; i <= n; i++)
    {
        if (ar[i] % 2 == 0) cn++;
        else in = i;
    }
    if (cn & 1)
        return player;
 
    else if (cn != n - 1 || ar[in] == 1)
        return (player ^ 1);
 
    ar[in]--;
    gcd = ar[1];
    for (int i = 2; i <= n; i++)
        gcd = __gcd(gcd, ar[i]);
 
    for (int i = 1; i <= n; i++)
        ar[i] /= gcd;
    calc(player ^ 1);
}
 
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) scanf("%d", &ar[i]);
    if (calc())
        puts("First");
    else
        puts("Second");
}