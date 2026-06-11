#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

long long n, x;
int a[5000];
int minima[4000][4000];
long long ans = 1e18;

int main()
{
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = n; i < 2 * n; i++) a[i] = a[i - n];
    for (int i = 0; i < 2 * n; i++)
    {
        int r = a[i];
        for (int j = i; j < 2 * n; j++)
        {
            r = min(r, a[j]);
            minima[i][j] = r;
        }
    }
    for (int c = 0; c < n; c++)
    {
        long long res = c * x;
        for (int j = n; j < 2 * n; j++)
        {
            res += minima[j - c][j];
        }
        ans = min(res, ans);
    }
    cout << ans;
}
