#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <array>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#define _USE_MATH_DEFINES
#include <cmath>
#include <climits>
#include <cstdio>
#include <iomanip>
#include <utility>
#include <unordered_map>

using namespace std;
typedef long long int ll;

#define SP(x) setprecision((int)x)
#define SW(x) setw(x) // 桁数指定
#define SF(c) setfill(c) // 埋め文字指定('0')
#define ALL(v) v.begin(), v.end()

int main(int argc, char const *argv[])
{
    ll n;
    cin >> n;
    vector<ll> v(1, 0);
    for (ll i = 0; i < n; i++)
    {
        ll t;
        cin >> t;
        v.push_back(v.back() + t);
    }
    ll m = LLONG_MAX;
    for (ll i = 1; i < n; i++)
    {
        m = min(m, abs(v.back() - v[i] * 2));
    }
    cout << m << endl;
}