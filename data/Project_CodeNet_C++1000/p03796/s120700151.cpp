#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool is_square(int n)
{
    for (int i = 0; i <= n; i++)
    {
        if (i * i == n)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    ll ans = 1;
    for (size_t i = 0; i < n; i++)
    {
        ans *= i + 1;
        ans = ans % (1000000000 + 7);
    }

    cout << ans << endl;

    return 0;
}