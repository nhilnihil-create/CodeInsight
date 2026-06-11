#include <iostream>
#include <vector>

using namespace std;

#define int long long

const int MOD = 1e9 + 7;

int n, l;
int a[500000];

signed main()
{
    cin >> n >> l;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int t = -1;
    for (int i = 0; i + 1 < n; i++)
    {
        if (a[i] + a[i + 1] >= l)
        {
            t = i;
        }
    }
    if (t == -1)
    {
        cout << "Impossible";
        return 0;
    }
    cout << "Possible\n";
    t++;
    for (int i = 1; i < t; i++)
    {
        cout << i << "\n";
    }
    for (int i = n - 1; i > t; i--)
    {
        cout << i << "\n";
    }
    cout << t << "\n";
}
