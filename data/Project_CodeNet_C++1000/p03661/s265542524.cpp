#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const ll INF = 1e15;

int main() {
    int n;
    cin >> n;

    ll a[n];
    ll sum = 0;
    rep(i, n) {
        cin >> a[i];
        sum += a[i];
    }

    ll ans = INF;
    ll snuke = 0;
    rep(i, n-1) {
        snuke += a[i];
        ll araiguma = sum - snuke;
        ll score = abs(snuke - araiguma);
        ans = min(ans, score);
    }

    cout << ans << endl;
    return 0;
}