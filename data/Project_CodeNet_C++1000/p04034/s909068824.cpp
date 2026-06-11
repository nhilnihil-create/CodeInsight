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
    int n, m;
    cin >> n >> m;
    vector<int> cnt(n, 1);
    vector<bool> ans(n, 0);
    ans[0] = true;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        --x, --y;
        if (ans[x])
        {
            ans[y] = true;
        }
        --cnt[x];
        ++cnt[y];
        if (cnt[x] == 0)
        {
            ans[x] = false;
        }
    }
    int a = 0;
    for (int i = 0; i < n; i++)
    {
        if (ans[i])
        {
            ++a;
        }
    }
    cout << a << endl;
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
}