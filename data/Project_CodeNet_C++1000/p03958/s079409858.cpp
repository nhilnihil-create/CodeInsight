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
    int k, t;
    cin >> k >> t;
    vector<int> a(t);
    for (int i = 0; i < t; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    if (k % 2 == 1)
    {
        if ((k + 1) / 2 >= a[0])
        {
            cout << 0 << endl;
            return 0;
        }
        else
        {
            cout << (a[0] - (k + 1) / 2) * 2 << endl;
            return 0;
        }
    }
    else
    {
        if (k / 2 >= a[0])
        {
            cout << 0 << endl;
            return 0;
        }
        else
        {
            cout << (a[0] - k / 2) * 2 - 1 << endl;
            return 0;
        }
    }
}
