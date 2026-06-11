#include <iostream>
#include <bitset>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <regex>
#include <iomanip>
#include <climits>
using namespace std;
using ll = long long int;
using dd = long double;
const ll MOD = 1e9 + 7;

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
    string S;
    cin >> S;
    map<char, ll> mp;

    for (ll i = 0; i < S.size(); i++)
    {
        mp[S[i]] += 1;
    }
    
    bool ok = true;
    for (auto &&e : mp)
    {
        if (e.second > 1) {
            ok = false;
        }
    }
    cout << (ok ? "yes" : "no") << endl;
}