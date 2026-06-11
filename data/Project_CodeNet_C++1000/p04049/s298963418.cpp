#include <algorithm>
#include <iostream>
#include <cstdio>
#include <map>
#include <numeric>
#include <cmath>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <complex>
#include <string.h>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <iomanip>
#include <sys/time.h>
#include <tuple>
#include <random>
using namespace std;

#define endl '\n'
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define UNIQ(v) (v).erase(unique((v).begin(), (v).end()), (v).end())

typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
typedef complex<double> comp;
typedef vector< vector<ld> > matrix;
struct pairhash {
public:
    template<typename T, typename U>
    size_t operator()(const pair<T, U> &x) const {
	size_t seed = hash<T>()(x.first);
	return hash<U>()(x.second) + 0x9e3779b9 + (seed<<6) + (seed>>2);
    }
};
const int inf = 1e9 + 9;
const ll mod = 1e9 + 7;
const double eps = 1e-8;
const double pi = acos(-1);

int n, k;
int a[2010], b[2010];

vector<int> G[2010];

int solve() {
    for (int i = 0; i < n-1; i++) {
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
    }

    int res = inf;
    bool used[2010];
    if (k % 2 == 0) {
        for (int i = 0; i < n; i++) {
            memset(used, false, sizeof(used));
            used[i] = true;
            queue<P> que;
            que.push(P(i, 0));
            while (!que.empty()) {
                P p =que.front(); que.pop();
                if (p.second >= k/2) continue;
                for (int v : G[p.first]) {
                    if (!used[v]) {
                        used[v] = true;
                        que.push(P(v, p.second+1));
                    }
                }
            }
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (used[i])
                    cnt++;
            }
            res = min(res, n-cnt);
        }
    } else {
        for (int i = 0; i < n-1; i++) {
            memset(used, false, sizeof(used));
            used[a[i]] = true;
            used[b[i]] = true;
            queue<P> que;
            que.push(P(a[i], 0));
            que.push(P(b[i], 0));
            while (!que.empty()) {
                P p =que.front(); que.pop();
                if (p.second >= k/2) continue;
                for (int v : G[p.first]) {
                    if (!used[v]) {
                        used[v] = true;
                        que.push(P(v, p.second+1));
                    }
                }
            }
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (used[i])
                    cnt++;
            }
            res = min(res, n-cnt);
        }
    }
    return res;
}

void input() {
    cin >> n >> k;
    for (int i = 0; i < n-1; i++) {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);

    input();
    cout << solve() << endl;
}
