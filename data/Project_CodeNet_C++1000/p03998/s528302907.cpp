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
    string a, b, c; cin >> a >> b >> c;
    int ia = 0, ib = 0, ic = 0;
    int next = 0;
    while (1) {
        if (next == 0) {
            if (ia == a.length()) {
                cout << "A" << endl;
                return 0;
            }
            next = a[ia] - 'a';
            ia++;
        } else if (next == 1) {
            if (ib == b.length()) {
                cout << "B" << endl;
                return 0;
            }
            next = b[ib] - 'a';
            ib++;
        } else {
            if (ic == c.length()) {
                cout << "C" << endl;
                return 0;
            }
            next = c[ic] - 'a';
            ic++;
        }
    }

    return 0;
}
