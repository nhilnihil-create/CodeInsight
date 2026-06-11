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
    int N, x;
    cin >> N >> x;
    vector<int> res(2 * N - 1);
    if(x == 1 || x == 2 * N - 1) {
        cout << "No" << endl;
        return 0;
    }
    res[N - 2] = 1;
    res[N] = 2 * N - 1;
    res[N - 1] = x;
    int num = 1;
    for(int i = 0; i < 2 * N - 1; i++) {
        if(res[i] == 0) {
            while(num == 1 || num == x)
                num++;
            res[i] = num;
            num++;
        }
    }
    cout << "Yes" << endl;
    rep(i, 2 * N - 1) { cout << res[i] << endl; }

    return 0;
}