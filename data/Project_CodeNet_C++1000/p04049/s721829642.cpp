#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <climits>
#include <cstring>

#define rep(i, m, n) for(int i=int(m);i<int(n);i++)
#define all(c) begin(c),end(c)

template<typename T1, typename T2>
inline void chmin(T1 &a, T2 b) { if (a > b) a = b; }

template<typename T1, typename T2>
inline void chmax(T1 &a, T2 b) { if (a < b) a = b; }

//改造
typedef long long int ll;
using ll = long long int;
using ull = long long unsigned int;
using Int = long long int;
using namespace std;
#define INF (1 << 30) - 1
#define INFl (ll)5e15
#define DEBUG 0 //デバッグする時1にしてね
#define dump(x)  cerr << #x << " = " << (x) << endl
#define MOD 1000000007


//ここから編集する
class Solve {
public:
    Int N, K;
    vector<vector<int>> G;
    vector<pair<int, int>> edge;
    vector<int> d;

    void bfs(int s1, int s2 = -1) {
        fill(all(d), INF);
        d[s1] = 0;
        if (s2 != -1) d[s2] = 0;

        queue<int> que;
        que.push(s1);
        if (s2 != -1) que.push(s2);

        while (!que.empty()) {
            int top = que.front();
            que.pop();
            for (auto v : G[top]) {
                if (d[v] == INF) {
                    d[v] = d[top] + 1;
                    que.push(v);
                }
            }
        }
    }

    void solve() {
        cin >> N >> K;
        G.resize(N);
        edge.resize(N);
        d.resize(N);
        for (int i = 0; i + 1 < N; ++i) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            G[a].push_back(b);
            G[b].push_back(a);
            edge.emplace_back(a, b);
        }


        if (K == 0) {
            cout << N - 1 << endl;
        } else if (K % 2) {
            int ans = INF;
            for (auto e : edge) {
                int s1 = e.first;
                int s2 = e.second;
                bfs(s1, s2);
                int tmp = 0;
                for (int i = 0; i < N; ++i) {
                    if (d[i] > K / 2) {
                        tmp++;
                    }
                }
                chmin(ans, tmp);
            }
            cout << ans << endl;
        } else {
            int ans = INF;
            for (int i = 0; i < N; ++i) {
                bfs(i);
                int tmp = 0;
                for (int i = 0; i < N; ++i) {
                    if (d[i] > K / 2) {
                        tmp++;
                    }
                }
                chmin(ans, tmp);
            }
            cout << ans << endl;
        }


    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    Solve().solve();


    return 0;
}
