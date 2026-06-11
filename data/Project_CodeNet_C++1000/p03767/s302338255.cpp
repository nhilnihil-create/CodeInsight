#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(3 * n);
    for (int i = 0; i < 3 * n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += a[1 + 2 * i];
    }
    
    cout << ans << endl;
}