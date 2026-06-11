#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    map<int, int> m;
    for(int i = 0; i < n; i++)
    {
        m[a[i]] = i % 2;
    }
    sort(a.begin(), a.end());
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(m[a[i]] != i % 2) ans++;
    }
    cout << ans / 2 << endl;
}
