#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <functional>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

int n, k, ans;
int a[100001];
int dist[100001];
vector<int> child[100001];
map<int, int> _vt[100001];
map<int, int> * pt[100001];

map<int, int> * merge(map<int, int> * x, map<int, int> * y) {
    if (x->size() < y->size()) return merge(y, x);
    for (pii i : *y) {
        (*x)[i.first] += i.second;
    }
    return x;
}

void dfs(int x) {
    pt[x] = _vt + x;
    for (int i : child[x]) {
        dist[i] = dist[x] + 1;
        dfs(i);
        pt[x] = merge(pt[x], pt[i]);
    }
    map<int, int>::iterator it = pt[x]->lower_bound(dist[x] + k);
    if (it != pt[x]->begin()) {
        --it;
        it->second = 1;
        pt[x]->erase(pt[x]->begin(), it);
    }
    else {
        (*pt[x])[dist[x]] = 1;
    }
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        dist[i] = -1;
    }
    dist[1] = 0;
    if (a[1] != 1) a[1] = 1, ++ans;
    for (int i = 2; i <= n; ++i) {
        child[a[i]].push_back(i);
    }
    for (int i : child[1]) {
        dist[i] = 1;
        dfs(i);
        for (pii j : (*pt[i])) {
            ans += j.second;
        }
        --ans;
    }
    printf("%d\n", ans);
	return 0;
}
