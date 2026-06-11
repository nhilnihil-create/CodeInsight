#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <iomanip>
#include <bitset>
#include <set>
#include <map>
#include <stdio.h>
#include <numeric>
#include <cstring>

#define rep(i,n) for (int i = 0; i < (n); i++)
#define rep1(i,n) for (int i = 1; i < (n); i++)
#define FOR(i,a,b) for (int i=(a); i < (b); i++)
#define MOD 1000000007 //10^9+7
#define ALL(a)  (a).begin(),(a).end()
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<long long, long long>;
const int INF = numeric_limits<int>::max();
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }

// 負の数にも対応した % 演算
long long mod(long long val, long long m) {
    long long res = val % m;
    if (res < 0) res += m;
    return res;
}

//greatest common divisor
long long gcd(ll a, ll b) 
{
    if (a % b == 0) {
        return b;
    } else {
        return gcd(b, a % b);
    }
}

//least common multiple
long long lcm(ll a, ll b)
{
    return a / gcd(a, b) * b ;
}

bool is_prime(ll n) {
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return n != 1;
}

int main()
{
    int n; cin >> n;
    vector<ll> a(n);
    int c1 = 0, c2 = 0, c4 = 0;
    rep(i,n) {
        cin >> a[i];
        if (a[i] % 2 == 1)
            c1++;
        else if (a[i] % 4 == 0)
            c4++;
        else
            c2++;
    }

    if (n % 2 == 0) {
        if (c2 % 2 == 0 && c1 -c4 <= 1)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    } else {
        if (c1 - c4 <= 1)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
