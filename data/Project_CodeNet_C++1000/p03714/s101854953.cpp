#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <iomanip>
#include <cassert>
#include <random>
#include <tuple>
#include <cstdint>
#include <complex>
#include <bitset>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};


int main() {
    int n; cin >> n;
    vector<int> a(3*n); rep(i, 3*n) cin >> a[i];

    priority_queue<int, vector<int>, greater<int>> to;
    priority_queue<int, vector<int>> rev;

    ll to_sum = 0;
    vector<ll> to_score(3*n+1);
    rep(i, n) {
        to_sum += a[i];
        to.push(a[i]);
    }
    to_score[n] = to_sum;
    for (int i = n; i < 2*n; i++) {
        to.push(a[i]);
        to_sum = to_sum - ll(to.top()) + ll(a[i]);
        to.pop();
        to_score[i+1] = to_sum;
    }

    ll rev_sum = 0;
    vector<ll> rev_score(3*n+1);
    for (int i = 3*n-1; i >= 2*n; i--) {
        rev_sum += a[i];
        rev.push(a[i]);
    }
    rev_score[2*n] = rev_sum;
    for (int i = 2*n-1; i >= n; i--) {
        rev.push(a[i]);
        rev_sum = rev_sum - ll(rev.top()) + ll(a[i]);
        rev.pop();
        rev_score[i] = rev_sum;
    }

    ll ans = -LINF;
    for (int i = n; i <= 2 * n; i++) {
        ans = max(ans, to_score[i] - rev_score[i]);
    }

    cout << ans << endl;


    return 0;
}


    
