#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
int INF = 1e9+10;
int main()
{
    int n;
    cin >> n;
    vector<int> p(n);
    for(int i = 0; i < n; i++)
    {
        cin >> p[i];
        p[i]--;
    }
    vector<int> a(n);
    vector<int> b(n);
    for(int i = 0; i < n; i++)
    {
        a[p[i]] = 1 + (p[i]) * n + i;
        b[p[i]] = 1 + (n-p[i]+1) * n;
    }
    for(int ans : a) cout << ans << " ";
    cout << endl;
    for(int ans : b) cout << ans << " ";
    cout << endl;
}
