#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <cstdio>

using namespace std;
#define prev prev55

long long n, m, a[500000], b[500000], ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    sort(a, a + n), sort(b, b + m);
    a[n] = 1e9, b[m] = 1e9;
    for (int i = 0, j = 0; i < n || j < m;)
    {
        if (a[i] < b[j])
        {
            ans += a[i] * (m + 1 - j);
            //cout << a[i] * (m + 1 - j) << " " << m + 1 - i << " A \n";
            i++;
        }
        else
        {
            ans += b[j] * (n + 1 - i);
            //cout << b[j] * (n + 1 - i) << " " << n + 1 - i << " B \n";
            j++;
        }
    }
    cout << ans;
}
