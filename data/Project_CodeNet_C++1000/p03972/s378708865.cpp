#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>
#include <functional>

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
#define dump(val) cerr << __LINE__ << ":\t" << #val << " = " << (val) << endl

using namespace std;

typedef long long int lli;
typedef tuple<int, int, int> tp;

template<typename T>
vector<T> make_v(size_t a, T b) {
    return vector<T>(a, b);
}

template<typename... Ts>
auto make_v(size_t a, Ts... ts) {
    return vector<decltype(make_v(ts...))>(a, make_v(ts...));
}

class UnionFind {
public:
    vector<int> par;
    int cnt;
    UnionFind(int n) {
        par.resize(n);
        REP(i, 0, n) {
            par[i] = i;
        }
        cnt = n;
    }
    int Find(int n) {
        return (n == par[n] ? n : par[n] = Find(par[n]));
    }
    bool Union(int a, int b) {
        a = Find(a);
        b = Find(b);
        if (a == b) return false;
        par[a] = b;
        cnt--;
        return true;
    }
    int getCnt() {
        return cnt;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int W, H;
    cin >> W >> H;
    priority_queue<tp, vector<tp>, greater<tp>> pq;
    UnionFind uf[2] = {UnionFind(W + 1), UnionFind(H + 1)};

    REP(i, 0, W) {
        int p;
        cin >> p;
        pq.emplace(p, i, 0);
    }
    REP(i, 0, H) {
        int q;
        cin >> q;
        pq.emplace(q, i, 1);
    }
    lli ans = 0;

    while (pq.size()) {
        int ind, t;
        lli c;
        tie(c, ind, t) = pq.top();
        pq.pop();
        ans += (uf[!t].getCnt()) * c;
        uf[t].Union(ind, ind + 1);
    }

    cout << ans << endl;
    return 0;
}
