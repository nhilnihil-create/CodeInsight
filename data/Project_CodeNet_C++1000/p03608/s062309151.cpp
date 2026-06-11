#include <algorithm>
#include <cassert>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <numeric>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define int long long int
#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(), (x).end()
#define capi(x) int x;cin>>x
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using vi = vector<int>;

template<class T>bool chmax(T &a, const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b){if(b<a){a=b;return 1;}return 0;}

class FloydWarshall {
public:
    const int size;
    vector<vector<int>> distance;

    FloydWarshall(const vector<vector<int>>& dist) :
        size(dist.size()),
        distance(dist) {
        for (int k = 0; k < size; ++k) {
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    if (distance[i][j] <= distance[i][k] + distance[k][j]) continue;
                    distance[i][j] = distance[i][k] + distance[k][j];
                }
            }
        }
    }
};

signed main() {
    int n, m, r;
    cin >> n >> m >> r;

    vi vr;
    rep(i, r) {
        capi(x); --x;
        vr.push_back(x);
    }

    vector<vector<int>> vc(n, vector(n, 1ll << 40));
    rep(i, m) {
        int a, b, c;
        cin >> a >> b >> c;
        --a; --b;

        vc[a][b] = c;
        vc[b][a] = c;
    }
    rep(i, n) {
        vc[i][i] = 0;
    }

    FloydWarshall fw(vc);

    sort(all(vr));
    int ans = 1ll << 40;

    do {
        int res = 0;
        rep(i, r - 1) {
            res += fw.distance[vr[i]][vr[i + 1]];
        }

        chmin(ans, res);
    } while(next_permutation(all(vr)));

    cout << ans;

    return 0;
}