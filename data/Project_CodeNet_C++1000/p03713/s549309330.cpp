#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
#include <math.h>
#include <bitset>
#include <queue>
#include <set>
#include <iomanip>
#include <assert.h>
#include <cstdio>

// #include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr long long int INFLL = 1001001001001001LL;
constexpr long long int infll = 1001001001001001LL;
constexpr int INF = 1000000007;
constexpr int inf = 1000000007;
const int mod = 1000000007;

inline bool chmin(ll &a, ll b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

inline bool chmax(ll &a, ll b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

template <typename T>
T seinomi(T a)
{
    if (a > 0)
    {
        return a;
    }
    else
    {
        return 0;
    }
}

//桁数取得
template <typename T>
T ketasuu(T num)
{
    return std::to_string(num).length();
}
//整数乗
ll llpow(ll a, ll n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        ll rep = a;
        for (ll i = 1; i < n; i++)
        {
            rep *= a;
        }
        return rep;
    }
}

template <class ForwardIt, class T>
void iota(ForwardIt first, ForwardIt last, T value)
{
    while (first != last)
    {
        *first++ = value;
        ++value;
    }
}

template <typename T>
T amarinasi(T a, T b)
{
    if (a % b == 0)
    {
        return a / b;
    }
    else if (a % b > 0)
    {
        return a / b + 1;
    }
    else
    {
        return a / b - 1;
    }
}

//小数点以下10桁テンプレート（main関数内の最初に貼付け）
//std::cout << std::fixed << std::setprecision(10);

//----------------------------------------------------------------
const double pi = 3.14159265358979323846264;

int main()
{
    ll h, w;
    cin >> h >> w;
    if (h % 3 == 0 || w % 3 == 0)
    {
        cout << 0 << endl;
    }
    else
    {
        ll ans = infll;
        for (ll i = 0; i < w - 2; i++)
        {
            ll s1 = i * h;
            ll s2 = ((w - i) / 2) * h;
            ll s3 = ((w - i + 2 - 1) / 2) * h;
            chmin(ans, max({s1, s2, s3}) - min({s1, s2, s3}));
        }
        for (ll i = 0; i < h - 2; i++)
        {
            ll s1 = i * w;
            ll s2 = ((h - i) / 2) * w;
            ll s3 = ((h - i + 2 - 1) / 2) * w;
            chmin(ans, max({s1, s2, s3}) - min({s1, s2, s3}));
        }
        for (ll i = 1; i < w; i++)
        {
            ll s1 = i * h;
            ll s2 = (w - i) * (h / 2);
            ll s3 = (w - i) * ((h + 2 - 1) / 2);
            chmin(ans, max({s1, s2, s3}) - min({s1, s2, s3}));
        }
        for (ll i = 1; i < h; i++)
        {
            ll s1 = i * w;
            ll s2 = (h - i) * (w / 2);
            ll s3 = (h - i) * ((w + 2 - 1) / 2);
            chmin(ans, max({s1, s2, s3}) - min({s1, s2, s3}));
        }
        cout << ans << endl;
    }
}