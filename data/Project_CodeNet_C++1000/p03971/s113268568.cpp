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

int main()
{
    ll N, A, B;
    cin >> N >> A >> B;
    string S;
    cin >> S;

    ll entry = 0;
    ll overseas = 0;

    for (ll i = 0; i < N; i++)
    {
        bool ok = false;
        if (S[i] == 'a')
        {
            if (entry < A + B) {
                ok = true;
                entry += 1;
            }
        }
        else if (S[i] == 'b')
        {
            if (overseas < B && entry < A + B) {
                ok = true;
                entry += 1;
                overseas += 1;
            }
        }
        cout << (ok ? "Yes" : "No") << endl;
    }
}