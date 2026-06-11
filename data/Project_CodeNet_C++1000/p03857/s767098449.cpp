#include <iostream>
#include <fstream>
#include <queue>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef __int128 lll;
constexpr ll mod = 1000000007;

int n, k[2], a[200000][2], p, q;

queue<int> v;

int root(int node, int tr) {
    int c = node;
    while (a[c][tr] != -1) {
        v.push(c);
        c = a[c][tr];
    }
    while (!v.empty()) {
        a[v.front()][tr] = c;
        v.pop();
    }
    return c;
}

int main() {
    cin >> n >> k[0] >> k[1];
    for (int i = 0; i < n; i++) a[i][0] = a[i][1] = -1;
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < k[j]; i++) {
            cin >> p >> q;
            if (root(p - 1, j) != root(q - 1, j)) a[root(p - 1, j)][j] = root(q - 1, j);
        }
    }
    map<pair<int, int>, int> w;
    for (int i = 0; i < n; i++) w[make_pair(root(i, 0), root(i, 1))]++;
    for (int i = 0; i < n; i++) cout << w[make_pair(root(i, 0), root(i, 1))] << endl;
}