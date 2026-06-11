#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
int main()
{

    ll n;
    cin >> n;
    vector<ll> a(n);

    rep(i, n)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<ll> hen;
    int cnt = 0;
    for (int i = n - 1; i > 0; i--)
    {
        if (a[i] == a[i - 1])
        {
            hen.push_back(a[i]);
            i--;
            cnt++;
        }
        if (cnt == 2)
        {
            cout << hen[0] * hen[1] << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}