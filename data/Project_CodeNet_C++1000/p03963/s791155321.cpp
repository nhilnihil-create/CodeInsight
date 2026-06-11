#include <bits/stdc++.h>
#include <numeric>
#include <algorithm>
#define _USE_MATH_DEFINES
#include <math.h>
#include <iomanip>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REP1(i, n) for(int i = 2; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
    ll n, k; cin >> n >> k;
    ll a = pow(k - 1, n - 1);
    cout << k * a << endl;
}