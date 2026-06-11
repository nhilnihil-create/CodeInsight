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

// const int MAX = 1010;

ll COM(int n, int r)
{
    ll semi = 1;
    ll denomi = 1;
    for (int i = 0; i < r; i++)
    {
        semi *= n - i;
        if (semi % (i + 1) == 0)
        {
            semi /= (i + 1);
        }
        else
        {
            denomi *= (i + 1);
        }
    }
    return semi / denomi;
}

int main()
{
    int n, p;
    cin >> n >> p;
    int odd = 0, even = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (a % 2 == 0)
        {
            ++even;
        }
        else
        {
            ++odd;
        }
    }
    ll ans = 0;
    for (int i = 0; i <= odd; i++)
    {
        if (i % 2 == p)
        {
            ans += COM(odd, i);
        }
    }
    ll tmp = 0;
    for (int i = 0; i <= even; i++)
    {
        tmp += COM(even, i);
    }
    ans *= tmp;
    cout << ans << endl;
    return 0;
}