#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for(int(i) = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for(int(i) = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define pb push_back
#define MP(a, b) make_pair((a), (b))
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> X(N);
    rep(i, N) cin >> X[i];
    sort(All(X));
    vector<int> mod(M + 1);
    vector<int> hist(100010);
    vector<int> same(M + 1);
    rep(i, N) {
        mod[X[i] % M]++;
        hist[X[i]]++;
        if(hist[X[i]] % 2 == 0)
            same[X[i] % M]++;
    }
    int res = 0;
    rep(i, M / 2 + 1) {
        if(i == 0 || (M % 2 == 0 && i == M / 2))
            res += mod[i] / 2;
        else {
            int a = mod[i];
            int b = mod[M - i];
            int c = same[i];
            int d = same[M - i];
            if(a < b) {
                swap(a, b);
                swap(c, d);
            }
            res += min(a, b);
            a -= b;
            res += min(c, a / 2);
        }
    }
    cout << res << endl;
    return 0;
}