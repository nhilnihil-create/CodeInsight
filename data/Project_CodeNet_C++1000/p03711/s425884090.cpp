#include <iostream>
#include <bitset>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <regex>
using namespace std;
using ll = long long int;
using dd = long double;
const ll MOD = 1e9 + 7;

vector<string> dfs(string s, ll depth, vector<char> symbol)
{
    vector<string> ret;
    if (depth == 0)
    {
        ret.push_back(s);
        return ret;
    }

    for (ll i = 0; i < symbol.size(); i++)
    {
        auto vec = dfs(s + symbol[i], depth - 1, symbol);
        for (auto &&e : vec)
        {
            ret.push_back(e);
        }
    }
    return ret;
}

ll gcd(ll a, ll b)
{
    if (a % b == 0)
    {
        return b;
    }
    return gcd(b, a % b);
}

int main()
{
    set<ll> a;
    set<ll> b;
    set<ll> c;

    a.insert(1);
    a.insert(3);
    a.insert(5);
    a.insert(7);
    a.insert(8);
    a.insert(10);
    a.insert(12);

    b.insert(4);
    b.insert(6);
    b.insert(9);
    b.insert(11);

    c.insert(2);

    ll x, y;
    cin >> x >> y;
    bool ok = (a.count(x) && a.count(y)) || (b.count(x) && b.count(y)) || (c.count(x) && c.count(y));

    if (ok)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}