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
#include <utility>
#include <queue>
using namespace std;
using ll = long long int;
using dd = long double;
const ll MOD = 1e9 + 7;
const dd PI = 3.1415926435;

ll gcd(ll a, ll b)
{
    if (a % b == 0)
    {
        return b;
    }
    return gcd(b, a % b);
}

ll fact(ll n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return 1;
    }
    return n * fact(n - 1) % MOD;
}

ll pow_fast(ll n, ll k)
{
    if (k == 0)
    {
        return 1;
    }
    if (k == 1)
    {
        return n;
    }

    if (k % 2 == 0)
    {
        ll tmp = pow_fast(n, k / 2LL);
        return tmp * tmp % MOD;
    }
    else
    {
        ll tmp = pow_fast(n, k / 2LL);
        tmp *= tmp;
        tmp %= MOD;
        return tmp * n % MOD;
    }
}

map<ll, ll> sosuu(ll n)
{
    map<ll, ll> res;
    for (ll i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            res[i] += 1;
            n /= i;
        }
    }
    if (n != 1)
    {
        res[n] += 1;
    }
    return res;
}

int main()
{
    string a, b, c;
    cin >> a >> b >> c;

    char cur = 'a';
    char ans;
    while (true)
    {
        if (cur == 'a') {
            if (a.size() == 0) {
                ans = 'A';
                break;
            }
            cur = a[0];
            a.erase(0, 1);
        } else if (cur == 'b') {
            if (b.size() == 0) {
                ans = 'B';
                break;
            }
            cur = b[0];
            b.erase(0, 1);
        } else if (cur == 'c') {
            if (c.size() == 0) {
                ans = 'C';
                break;
            }
            cur = c[0];
            c.erase(0, 1);
        }
    }
    cout << ans << endl;
}