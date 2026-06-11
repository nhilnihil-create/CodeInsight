#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
int INF = 1e9+10;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    if(a[0] + 1 < a[n-1])
    {
        cout << "No" << endl;
        return 0;
    }
    if(a[0] == a[n-1])
    {
        if(a[0] == n-1 || a[0] * 2 <= n)
        {
            cout << "Yes" << endl;
            return 0;
        }
        else
        {
            cout << "No" << endl;
            return 0;
        }
    }
    int num = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] == a[0]) num++;
    }
    if(num > a[0])
    {
        cout << "No" << endl;
        return 0;
    }
    int d = a[0] - num;
    if(2 * (d + 1) <= n - num) cout << "Yes" << endl;
    else cout << "No" << endl;
}
