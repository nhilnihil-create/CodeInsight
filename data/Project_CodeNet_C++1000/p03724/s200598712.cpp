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
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        mp[a]++;
        mp[b]++;
    }
    bool flag = true;
    for (auto m : mp)
    {
        if (m.second % 2 != 0)
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
