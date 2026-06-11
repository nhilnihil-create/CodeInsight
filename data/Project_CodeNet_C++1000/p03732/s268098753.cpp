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
    ll n;
    ll w;
    cin >> n >> w;
    vector<ll> data0;
    vector<ll> data1;
    vector<ll> data2;
    vector<ll> data3;
    ll fstw, fstv;
    cin >> fstw >> fstv;
    data0.push_back(fstv);
    for (ll i = 1; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        if (a - fstw == 0)
        {
            data0.push_back(b);
        }
        if (a - fstw == 1)
        {
            data1.push_back(b);
        }
        if (a - fstw == 2)
        {
            data2.push_back(b);
        }
        if (a - fstw == 3)
        {
            data3.push_back(b);
        }
    }
    sort(data0.begin(), data0.end(), greater<ll>());
    sort(data1.begin(), data1.end(), greater<ll>());
    sort(data2.begin(), data2.end(), greater<ll>());
    sort(data3.begin(), data3.end(), greater<ll>());
    ll ans = 0;
    for (ll i = 0; i <= data0.size(); i++)
    {
        for (ll j = 0; j <= data1.size(); j++)
        {
            for (ll k = 0; k <= data2.size(); k++)
            {
                for (ll l = 0; l <= data3.size(); l++)
                {
                    if (i * fstw + j * (fstw + 1) + k * (fstw + 2) + l * (fstw + 3) > w)
                    {
                        continue;
                    }
                    //cout << i << j << k << l << endl;
                    ll tmp = 0;
                    for (ll o = 0; o < i; o++)
                    {
                        tmp += data0[o];
                    }
                    for (ll o = 0; o < j; o++)
                    {
                        tmp += data1[o];
                    }
                    for (ll o = 0; o < k; o++)
                    {
                        tmp += data2[o];
                    }
                    for (ll o = 0; o < l; o++)
                    {
                        tmp += data3[o];
                    }
                    chmax(ans, tmp);
                }
            }
        }
    }
    cout << ans << endl;
}
