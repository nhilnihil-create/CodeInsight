#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <bitset>
#include <tuple>
using namespace std;
typedef long long ll;

int par[200010];
int rnk[200010];
ll sze[200010];
 
// 初期化
void init(int n) {
    for (int i = 0; i < n; i++) {
        par[i] = i;
        rnk[i] = 0;
        sze[i] = 1;
    }
}
 
// 親探し
int find(int x) {
    if (par[x] == x) return x;
    else return par[x] = find(par[x]);
}
 
// 併合
void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (rnk[x] < rnk[y]) {
        sze[y] = sze[x] + sze[y];
        par[x] = y;
    }
    else {
        sze[x] = sze[x] + sze[y];
        par[y] = x;
        if (rnk[x] == rnk[y]) rnk[x]++;
    }
    
}
 
// 同じ木にあるか
bool same(int x, int y) {
    return find(x) == find(y);
}

int main() {
    int n, k, l;
    cin >> n >> k >> l;

    init(n);
    for (int i = 0; i < k; i++) {
        int p, q;
        cin >> p >> q;
        unite(p - 1, q - 1);
    }

    int road[200010];
    for (int i = 0; i < n; i++) {
        road[i] = find(i);
    }

    init(n);
    for (int i = 0; i < l; i++) {
        int p, q;
        cin >> p >> q;
        unite(p - 1, q - 1);
    }

    int train[200010];
    for (int i = 0; i < n; i++) {
        train[i] = find(i);
    }

    int ans[200010] = {};
    vector<tuple<int, int, int>> v;
    for (int i = 0; i < n; i++) {
        v.emplace_back(road[i], train[i], i);
    }
    sort(v.begin(), v.end());

    int idx = 0;
    while (idx < n) {
        if (ans[get<2>(v[idx])] == 0) {
            int sub = 0;
            vector<int> w;
            while (get<0>(v[idx]) == get<0>(v[idx + sub]) 
            && get<1>(v[idx]) == get<1>(v[idx + sub]) 
            && idx + sub < n) {
                w.push_back(get<2>(v[idx + sub]));
                sub++;
            }
            for (int i = 0; i < w.size(); i++) {
                ans[w[i]] = sub;
            }
            idx += sub;
        }
        else idx++;
    }

    for (int i = 0; i < n; i++) {
        if (i != 0) cout << " ";
        cout << ans[i];
    }
    cout << endl;


}
