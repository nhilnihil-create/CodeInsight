#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <random>

using namespace std;

const int N = 1e5 + 7;

int gr[N];
int used[N];
vector<int> g[N];

int mexx(vector<int> cur) {
    if (cur.empty()) return 0;
    sort(cur.begin(), cur.end());
    if (cur.front() != 0) {
        return 0;
    }
    for (int i = 0; i + 1 < (int)cur.size(); i++) {
        if (cur[i] + 1 < cur[i + 1]) {
            return cur[i] + 1;
        }
    }
    return cur.back() + 1;
}

void dfs(int cur) {
    used[cur] = 1;
    vector<int> sons;
    for (auto t : g[cur]) {
        if (!used[t]) {
            dfs(t);
            sons.push_back(t);
        }
    }
    if (sons.empty()) {
        gr[cur] = 0;
    } else {
        for (auto t : sons) {
            gr[cur] ^= (gr[t] + 1);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i + 1 < n; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(0);
    // for (int i = 0; i < n; i++) {
    //     cerr << i + 1 << ' ' << gr[i] << endl;
    // }
    if (!gr[0]) {
        cout << "Bob\n"; 
    } else {
        cout << "Alice\n";
    }
}       
