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
    string s;
    ll k;
    cin >> s >> k;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'a')
        {
            continue;
        }
        if ('z' - s[i] + 1 <= k)
        {
            k -= ('z' - s[i] + 1);
            s[i] = 'a';
        }
    }
    k %= 26;
    s[n - 1] += k;
    cout << s << endl;
    return 0;
}
