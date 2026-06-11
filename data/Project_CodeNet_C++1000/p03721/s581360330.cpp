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
    int n; ll k;
    cin >> n >> k;

    set<ll> a;
    map<int, int> a_b;
    rep(i, n) {
        int c, b; cin >> c >> b;
        a.insert(c);
        a_b[c] += b; 
    }

    ll sum = 0; ll ans = 0; auto itr = a.begin();
    do {
        sum += a_b[*itr];
        ans = *itr; itr++;
    }
    while (k > sum);

    cout << ans << endl;
    return 0;
}