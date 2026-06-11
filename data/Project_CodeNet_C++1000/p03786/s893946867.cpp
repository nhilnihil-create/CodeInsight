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
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (ll i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    
    sort(A.begin(), A.end());

    ll ans = -1;
    ll sum = 0;
    for (ll i = 0; i < N - 1; i++)
    {
        sum += A[i];
        if (sum * 2 < A[i + 1]) {
            ans = i;
        }
    }
    cout << (N - ans - 1) << endl;
}