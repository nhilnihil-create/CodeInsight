#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const int INF = 1001001001;
const int MOD = 1000000007;

template <typename T>
void print(const T &v);

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }
    if (n % 2 == 1)
    {
        a.push_back(0);
    }
    sort(a.begin(), a.end());
    int num;
    if (n % 2 == 0)
    {
        num = 1;
    }
    else
    {
        num = 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] != num)
        {
            cout << 0 << endl;
            return 0;
        }
        if (i % 2 == 1)
        {
            num += 2;
        }
    }
    ll ans = 1;
    for (int i = 0; i < n / 2; i++)
    {
        ans = (ans * 2ll) % MOD;
    }
    cout << ans << endl;
    return 0;
}

// Use For Debug
template <typename T>
void print(T const &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << " ";
        cout << v[i];
    }
    cout << endl;
}
