#include <iostream>
#include <bitset>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
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

enum Tenki
{
    Sunny,
    Cloudy,
    Rainy
};

int main()
{
    map<ll, ll> mp;
    mp[2] = 1;
    mp[3] = 2;
    mp[4] = 3;
    mp[5] = 4;
    mp[6] = 5;
    mp[7] = 6;
    mp[8] = 7;
    mp[9] = 8;
    mp[10] = 9;
    mp[11] = 10;
    mp[12] = 11;
    mp[13] = 12;
    mp[1] = 13;

    ll A, B;
    cin >> A >> B;

    if (mp[A] == mp[B]) {
        cout << "Draw" << endl;
    } else if (mp[A] < mp[B]) {
        cout << "Bob" << endl;
    } else {
        cout << "Alice" << endl;
    }
}