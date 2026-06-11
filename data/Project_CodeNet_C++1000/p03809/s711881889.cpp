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
using namespace std;
#define INF (1 << 30) - 1
#define INFl (ll)5e15
#define DEBUG 0 //デバッグする時1にしてね
#define dump(x)  cerr << #x << " = " << (x) << endl
#define MOD 1000000007


//ここから編集する
class Solve {
public:
    int N;
    vector<ll> A;
    vector<vector<int>> treeone;

    void input() {
        cin >> N;
        A.resize(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        treeone.resize(N);
        for (int i = 0; i < N - 1; ++i) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            treeone[a].push_back(b);
            treeone[b].push_back(a);
        }
    }

    bool flag = true;

    ll dfs(int n, int p) {
        if (treeone[n].size() == 1 && p != -1) return A[n];
//        ll par = 2 * A[n];
//        if(treeone[n].size() == 1) par = A[n];

        ll chi = 0;
        ll max_chi = 0;
        for (auto e : treeone[n]) {
            if (e != p) {
                ll tmp = dfs(e, n);
                chi += tmp;
                chmax(max_chi, tmp);
            }
        }
        if (A[n] > chi) flag = false;
        ll ret = 2 * A[n] - chi;
        if (ret < 0) flag = false;
        if (ret < 2 * max_chi - chi) flag = false;

        return ret;
    }

    void solve() {
        input();
        int leaf;
        for (int i = 0; i < N; ++i) {
            if (treeone[i].size() == 1) {
                leaf = i;
                break;
            }
        }
        ll val = dfs(leaf, -1);
        if (val == A[leaf] && flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
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
