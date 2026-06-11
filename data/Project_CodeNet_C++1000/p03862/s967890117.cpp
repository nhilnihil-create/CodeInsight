#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define Yes                \
    cout << "Yes" << endl; \
    return 0;
#define No                \
    cout << "No" << endl; \
    return 0;
using namespace std;
using ll = long long;
const int INF = 1001001001;
const int MOD = 1000000007;
typedef long long ll;

template <typename T>
void print(const T &v);

int main()
{
    ll N, x;
    cin >> N >> x;
    vector<ll> a(N);
    rep(i, N) cin >> a[i];
    ll ans = 0;
    for (int i = 0; i < N - 1; i++)
    {
        ll total = a[i] + a[i + 1];
        if (total > x)
        {
            ans += total - x;
            a[i + 1] -= total - x;
            if (a[i + 1] < 0)
            {
                a[i] -= abs(a[i + 1]);
                a[i + 1] = 0;
            }
        }
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
