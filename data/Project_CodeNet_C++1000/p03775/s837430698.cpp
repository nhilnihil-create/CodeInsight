#include <bits/stdc++.h>
using namespace std;

int main()
{
    long n;
    cin >> n;
    int ans = 0;
    long x = (long)sqrt(n);
    while (x > 0)
    {
        if (n % x == 0)
        {
            long b = n / x;
            while (b > 0)
            {
                ans++;
                b /= 10;
            }
            cout << ans << endl;
            return 0;
        }
        x--;
    }
}