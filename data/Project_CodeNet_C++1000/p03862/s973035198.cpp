#include <iostream>
using namespace std;

void solve()
{
    int N;
    cin >> N;
    int x;
    cin >> x;
    int a[N];
    for (int i = 0; i < N; ++i)
    {
        cin >> a[i];
    }
    long long ans = 0;
    for (int i = 1; i < N; ++i)
    {
        if (a[i] + a[i - 1] > x)
        {
            if (a[i-1]<= x)
            {
                ans += a[i] - x + a[i-1];
                a[i] -= a[i]-x+a[i-1];
            }
            else
            {
                ans += a[i] + a[i - 1] - x;
                a[i - 1] = x;
                a[i] = 0;
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}