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
bool chmax(T &a, const T &b) { if (a < b) { return b; } return a; }

template<class T>
bool chmin(T &a, const T &b) { if (a > b) { a = b; return a; } return a; }

int main() {
    ll w, h, n; 
    cin >> w >> h >> n;

    vector<pair<ll, ll>> coords(n); vector<ll> a(n);
    rep(i, n) cin >> coords[i].first >> coords[i].second >> a[i];

    ll min_w = 0; ll min_h = 0;
    rep(i, n) {
        if (w == 0 || h == 0) { cout << 0 << endl; return 0; }
        if (a[i] == 1) min_w = max(coords[i].first, min_w);
        if (a[i] == 2) w = min(coords[i].first, w);
        if (a[i] == 3) min_h = max(coords[i].second, min_h);
        if (a[i] == 4) h = min(coords[i].second, h);

        if (w-min_w <= 0 || h-min_h <= 0) { cout << 0 << endl; return 0; }
    }
    
    cout <<  (w-min_w)*(h-min_h) << endl;
    return 0;
}