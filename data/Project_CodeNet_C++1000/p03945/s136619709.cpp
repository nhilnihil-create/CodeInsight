#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <map>
#include <cmath>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

#define rep(i, o) for (ll i = 0; i < (o);i++)
#define rep_s(i, o) for (int i = 1; i <= (o);i++)
#define REP(i,a,b)for(int i=(int)(a);(i)<(int)(b);i++)
#define NUM 1e5

typedef long long ll;
typedef unsigned long long ull;

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll c, ll d) { return c / gcd(c, d) * d; }


template<class T>
bool chmax(T &a, const T &b) {
    if (a < b)
    {
        return b;
    }
    return a; 
}

template<class T>
bool chmin(T &a, const T &b) {
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0; 
}

int main() {
    string s; cin >> s;

    ll n = s.size();
    ll l = 0; ll count = 0;
    rep(i, n) {
        if (i != n-1 && s[i] != s[i+1]) count++;
        if (s[i] == 'W') l++;
    }
    
    ll r = 0;
    for (int i = n-1; i >= 0; i--)
    {
        if (i != 0 && s[i] != s[i-1]) count++;
        if (s[i] == 'B') r++;
    }

    // cout << l << " " << r << endl;
    ll ans = 0;
    if (count == 2*n-2) ans = n - 1;
    else if (0 == l || 0 == r) ans = 0;
    else if (n == l + r && count == 2) ans = 1;
    else ans = count/2;
    cout << ans << endl;
    return 0;
}