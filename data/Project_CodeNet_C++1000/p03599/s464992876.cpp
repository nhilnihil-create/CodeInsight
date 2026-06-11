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
    ll a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    ll max_bunshi = 0;
    ll max_bunbo = 100 * a;
    for (ll i = 0; i <= (f / (a * 100)); i++)
    {
        for (ll j = 0; j <= (f - a * 100 * i) / (b * 100); j++)
        {
            ll mizu = a * 100 * i + b * 100 * j;
            for (ll k = 0; k <= (f - mizu) / c; k++)
            {
                for (ll l = 0; l <= (f - mizu - k * c) / d; l++)
                {
                    ll bunshi = 100 * (c * k + d * l);
                    ll bunbo = mizu + (c * k + d * l);
                    if (bunshi * (100 + e) <= 100 * e * bunbo)
                    {
                        if (bunshi * (max_bunbo) > max_bunshi * bunbo)
                        {
                            max_bunshi = bunshi;
                            max_bunbo = bunbo;
                        }
                    }
                }
            }
        }
    }
    cout << max_bunbo << " " << max_bunshi / 100 << endl;
}