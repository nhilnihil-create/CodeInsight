#include <bits/stdc++.h>

using namespace std;

namespace {
    int N, K, L;

    /** output whole vector. ex) vector<int>{1, 2, 3} -> '1 2 3'. */
    template<typename T>
    ostream& operator<<(ostream& os, const vector<T>& xs) {
       if (xs.empty()) return os;
       os << xs[0];
       for (auto i = 1; i < xs.size(); i++) os << ' ' << xs[i];
       return os;
    }

    struct UnionFind {
        int N;
        vector<int> P;
        UnionFind(int N) : N(N) {
            P.clear();
            P.resize(N, -1);
        }
        int root(int x) {
            if (P[x] == -1) return x;
            return P[x] = root(P[x]);
        }
        int query(int x, int y) { return root(x) == root(y); }
        void merge(int x, int y) {
            x = root(x);
            y = root(y);
            if (x == y) return;
            P[x] = y;
        }
    };

    void solve() {
        cin >> N >> K >> L;
        UnionFind a(N), b(N);
        for (int i = 0; i < K; i++) {
            int p, q; cin >> p >> q;
            p--; q--;
            a.merge(p, q);
        }
        for (int i = 0; i < L; i++) {
            int r, s; cin >> r >> s;
            r--; s--;
            b.merge(r, s);
        }
        map<pair<int, int>, int> C;
        for (int i = 0; i < N; i++) {
            C[make_pair(
                a.root(i),
                b.root(i)
            )] += 1;
        }
        vector<int> ans;
        for (int i = 0; i < N; i++) {
            ans.push_back(C[make_pair(a.root(i), b.root(i))]);
        }
        cout << ans << endl;
    }
}

int main() {
    solve();
    return 0;
}

