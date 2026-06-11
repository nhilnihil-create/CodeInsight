#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;

    ll mint = 1, mina = 1;
    for (int i = 0; i < n; i++)
    {
        ll t = max(mint / a[i].first + (mint % a[i].first != 0),
                   mina / a[i].second + (mina % a[i].second != 0));
        mint = a[i].first * t;
        mina = a[i].second * t;
    }
    cout << mint + mina << endl;
}
