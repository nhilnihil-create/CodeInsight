#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const int MAX_N = 1010;
const int MAX_M = 2010;
const ll INF = 1e16;

int main() {
    int n, m;
    cin >> n >> m;

    vector<ll> a(MAX_M), b(MAX_M), c(MAX_M);
    rep(i, m) {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--;  b[i]--;
        c[i] *= -1;
    }

    vector<ll> dist(MAX_N);
    rep(i, n) {
        dist[i] = INF;
    }

    dist[0] = 0;
    rep(loop, n-1) {
        rep(i, m) {

            if(dist[a[i]] == INF) {
                continue;
            }

            dist[b[i]] = min(dist[b[i]], dist[a[i]] + c[i]);

        }
    }

    ll ans = dist[n-1];

    vector<bool> negative(MAX_N);

    rep(loop, n) {
        rep(i, m) {

            if(dist[a[i]] == INF) {
                continue;
            }

            if(dist[b[i]] > dist[a[i]] + c[i]) {
                dist[b[i]] = dist[a[i]] + c[i];
                negative[b[i]] = true;
            }

            if(negative[a[i]]) {
                negative[b[i]] = true;
            }

        }
    }

    if(negative[n-1]) {
        cout << "inf";
    }
    else {
        cout << -ans;
    }

    cout << endl;
    return 0;
}