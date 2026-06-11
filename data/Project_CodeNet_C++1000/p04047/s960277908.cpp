#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    n *= 2;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int ans = 0;
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    for(int i = 1; i < n; i+=2)
    {
        ans += a[i];
    }
    cout << ans << endl;
}

