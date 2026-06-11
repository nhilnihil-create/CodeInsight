#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <random>
#include <string>
#include <bitset>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <cstring>
#include <cstdlib>
#include <cctype>

#define rep(i, n) for(int i = 0; i < n; ++i)
#define repr(i, n) for(int i = n; i >= 0; --i)
#define FOR(i, m, n) for(int i = m; i < n; ++i)
#define FORR(i, m, n) for(int i = m; i >= n; --i)
#define SORT(v, n) sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
#define INF 999999999

using namespace std;

typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;

int dy[] = {0, 0, 1, -1, 0};
int dx[] = {1, -1, 0, 0, 0};

llong pow(int x, int n) {
    llong ans = x;
    if (n == 0) return 1;

    for(int i = 0; i < n - 1; i++) {
        ans *= x;
    }

    return ans;
}

void swap(int *X, int *Y){
    int t = *X; *X = *Y; *Y = t;
}

int main() {
    llong h, w, n, a, b, cnt[10], sum = 0;
    cin >> h >> w >> n;
    map<pair<int, int>, int> M;

    rep(i, n) {
        cin >> a >> b;
        for (int j = a - 2; j <= a; ++j) {
            for (int k = b - 2; k <= b; ++k) {
                if (1 <= j && j + 2 <= h && 1 <= k && k + 2 <= w) {
                    M[make_pair(j, k)]++;
                }
            }
        }
    }

    memset(cnt, 0, sizeof(cnt));

    for (auto it = M.begin(); it != M.end(); it++) {
        cnt[it->second]++;
    }

    FOR(i, 1, 10) sum += cnt[i];

    cout << (h - 2) * (w - 2) - sum << endl;

    FOR(i, 1, 10) cout << cnt[i] << endl;

    return 0;
}