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
#include <math.h>
#include <assert.h>
// #include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr long long int INFLL = 1001001001001001LL;
constexpr int INF = 1000000007;
const int mod = 1000000007;

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

//----------------------------------------------------------------

int main()
{
    ll n, t;
    cin >> n >> t;
    ll a;
    cin >> a;
    long long before = 0;
    long long muda = 0;
    for (int i = 1; i < n; i++)
    {
        cin >> a;
        if (a - before < t)
        {
            muda += t - a + before;
        }
        before = a;
    }
    cout << n * t - muda << endl;
}
