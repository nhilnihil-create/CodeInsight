/*
    Author:zeke
    
    pass System Test!
    GET AC!!
*/
#include <iostream>
#include <queue>
#include <vector>
#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>
#include <functional>
#include <cmath>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <map>
#include <iomanip>
#include <utility>
#include <stack>
#include <bitset>
using ll = long long;
using ld = long double;
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define rep3(var, min, max) for (ll(var) = (min); (var) < (max); ++(var))
#define repi3(var, min, max) for (ll(var) = (max)-1; (var) + 1 > (min); --(var))
#define Mp(a, b) make_pair((a), (b))
#define F first
#define S second
#define Icin(s) \
    ll(s);      \
    cin >> (s);
#define Scin(s) \
    ll(s);      \
    cin >> (s);
template <class T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
    if (b < a)
    {
        a = b;
        return 1;
    }
    return 0;
}
typedef pair<ll, ll> P;
typedef vector<ll> V;
typedef vector<V> VV;
typedef vector<P> VP;
ll mod = 1e9 + 7;
ll MOD = 1e9 + 7;
ll INF = 1e18;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    V vec(n);
    rep(i, n) cin >> vec[i];
    ll Max = 0;
    ll Min = 1e18;
    rep(i, n)
    {
        chmax(Max, vec[i]);
        chmin(Min, vec[i]);
    }
    if (Max - Min > 1)
    {
        cout << "No" << endl;
        return 0;
    }
    ll MinCount = 0;
    ll MaxCount = 0;
    rep(i, n)
    {
        if (vec[i] == Min)
        {
            MinCount++;
        }
        else
        {
            MaxCount++;
        }
    }
    if (Max == Min)
    {
        if (n >= Max * 2 || Max == n - 1)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    else
    {
        if (MaxCount>=2*(Max-MinCount)&&MinCount<Max)
        {
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
}
