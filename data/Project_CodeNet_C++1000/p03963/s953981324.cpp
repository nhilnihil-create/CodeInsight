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
double distance(double x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main()
{
    int n,k;
    cin >> n >> k;
    ll ans=k;
    for (size_t i = 0; i < n-1; i++)
    {
        ans *= k - 1;
    }
    cout << ans << endl;

    return 0;
}