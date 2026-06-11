#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <map>
#include <cmath>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

#define rep(i, o) for (int i = 0; i < (o); ++i)
#define REP(i,a,b)for(int i=(int)(a);(i)<(int)(b);i++)
#define NUM 1e5

typedef long long ll;
typedef unsigned long long ull;

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll c, ll d) { return c / gcd(c, d) * d; }

const ll MOD = 1000000007;

int main() {
    ll n, m;
    cin >> n >> m;
    if (abs(n-m) > 1) { cout << 0 << endl; return 0; }

    ll fact_n = 1, fact_m = 1; 
    for (ll i = n; i > 0; i--) fact_n = (fact_n * i) % MOD;
    for (ll i = m; i > 0; i--) fact_m = (fact_m * i) % MOD;

    ll ans = 0;
    if (n == m) ans = (fact_n%MOD) * (fact_m%MOD) * 2;
    else ans = (fact_n%MOD) * (fact_m%MOD);
    cout << (ans%MOD) << endl;
    return 0;
}