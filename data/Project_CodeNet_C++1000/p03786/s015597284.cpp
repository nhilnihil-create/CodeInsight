#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1001001001;
const ll LINF = 1LL << 60;
const int MOD = 1'000'000'007;

template <typename T>
void print(const T &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << ' ';
        cout << v[i];
    }
    cout << endl;
}

template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<ll> sums(n + 1);
    for (int i = 0; i < n; i++)
    {
        sums[i + 1] = sums[i] + a[i];
    }
    int start_idx = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (sums[i + 1] * 2 < a[i + 1])
        {
            start_idx = i + 1;
        }
    }
    cout << n - start_idx << endl;
    return 0;
}
