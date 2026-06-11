#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1001001001;
const ll LINF = 1001001001001001;
const int MOD = 1000000007;

template <typename T>
void print(const T &v);

int main()
{
    int n, c, k;
    cin >> n >> c >> k;
    vector<ll> t(n);
    for (int i = 0; i < n; i++)
    {
        cin >> t[i];
    }
    sort(t.begin(), t.end());
    int ans = 0;
    int cnt = 0;  // 乗客数
    ll start = 0; // 出発時間
    for (int i = 0; i < n; i++)
    {
        if (start == 0)
        {
            start = t[i];
        }
        if (t[i] > start + k || cnt >= c)
        {
            ++ans;
            start = t[i];
            cnt = 1;
        }
        else
        {
            ++cnt;
        }
    }
    cout << ans + 1 << endl;
    return 0;
}

// Use For Debug
template <typename T>
void print(T const &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << ' ';
        cout << v[i];
    }
    cout << endl;
};