#include <bits/stdc++.h>
using namespace std;

class UnionFind {
    vector<int> parent;

    public:
        UnionFind(int size) {
            parent = vector<int>(size, -1);
        }

        int find(int x) {
            if (parent[x] < 0) {
                // parent itself
                return x;
            } else {
                return parent[x] = find(parent[x]);
            }
        }

        bool unite(int x, int y) {
            int rX, rY;
            if ((rX = find(x)) == (rY = find(y))) {
                // already united
                return false;
            }
            if (size(rX) < size(rY)) {
                int tmp = rX;
                rX = rY;
                rY = tmp;
            }
            parent[rX] += parent[rY];
            parent[rY] = rX;
            return true;
        }

        int size(int x) {
            return -parent[find(x)];
        }

        bool isSame(int x, int y) {
            return find(x) == find (y);
        }
};

int main() {
    int n, k, l;
    cin >> n >> k >> l;
    UnionFind road(n);
    UnionFind train(n);

    int p, q;
    for (int i = 0; i < k; i++) {
        cin >> p >> q;
        road.unite(p - 1, q - 1);
    }
    for (int i = 0; i < l; i++) {
        cin >> p >> q;
        train.unite(p - 1, q - 1);
    }

    vector<pair<int, int>> keys;
    map<pair<int, int>, int> count;
    for (int i = 0; i < n; i++) {
        pair<int, int> key = make_pair(road.find(i), train.find(i));
        keys.push_back(key);
        count[key]++;
    }

    for (const auto key : keys) {
        cout << count[key] << endl;
    }
}
