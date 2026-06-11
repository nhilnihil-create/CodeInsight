# include <iostream>
# include <cmath>

using namespace std;

int main()
{
    long long n, a[1010], t[1010];
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> t[i] >> a[i];
    }
    long long x = 1ll;
    for (int i = 1; i < n; ++i)
    {
        x = max( (t[i-1]*x + t[i] - 1) / t[i], (a[i-1] * x + a[i] - 1) / a[i]);
    }
    cout << x * t[n-1] + x*a[n-1];
    return 0;
}
