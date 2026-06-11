#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using VVI = vector<vector<int>>;
const int INF = 1001001001;
const int MOD = 1000000007;

template <typename T>
void print(const T &v);

int main()
{
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll mini = 1'000'000'000'000'000;
    for (int tmp = 0; tmp < (1 << n); tmp++)
    {
        bitset<15> bs(tmp);
        if (bs.count() < k || !bs.test(0))
        {
            continue;
        }
        ll top = a[0];
        ll cnt = 0;
        for (int i = 1; i < n; i++)
        {
            if (bs.test(i) && a[i] <= top)
            {
                cnt += (top - a[i] + 1);
                ++top;
            }
            else
            {
                top = max(a[i], top);
            }
        }
        mini = min(mini, cnt);
    }
    cout << mini << endl;
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