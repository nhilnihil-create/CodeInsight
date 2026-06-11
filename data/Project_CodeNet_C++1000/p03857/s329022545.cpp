#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <cstring>

using namespace std;
// ascending order
#define vsort(v) sort(v.begin(), v.end())
// descending order
#define vsort_r(v) sort(v.begin(), v.end(), greater<int>())
#define vunique(v) unique(v.begin(), v.end())
#define mp make_pair
#define ts(x) to_string(x)
#define rep(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define repm(i, a, b) for(int i = (int)a; i > (int)b; i--)
#define bit(a) bitset<8>(a)
#define des_priority_queue priority_queue<int, vector<int>, greater<int> >
typedef long long ll;
typedef pair<int, int> P;
const ll INF = 1e18;

int N, K, L;
int p[100010], q[100010];
int r[100010], s[100010];
const int MAX_N = 200010;

struct UnionFind {
    int par[MAX_N]; // 親
    int depth[MAX_N]; // 木の深さ


    // n要素で初期化
    void init(int n) {
        rep(i, 0, n) {
            par[i] = i;
            depth[i] = 0;
        }
    }

    // 木の根を求める
    int find(int x) {
        if(par[x] == x) return x;
        else return par[x] = find(par[x]);
    }

    // xとyの属する集合を併合
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if(x == y) return;

        if(depth[x] < depth[y]) {
            par[x] = y;
        } else {
            par[y] = x;
            if(depth[x] == depth[y]) depth[x]++;
        }
    }

    // xとyが同じ集合に属するか否か
    bool same(int x, int y) {
        return find(x) == find(y);
    }
};


int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
    UnionFind uf1, uf2;
    cin >> N >> K >> L;
    uf1.init(N);
    uf2.init(N);

    rep(i, 0, K) {
        cin >> p[i] >> q[i];
        uf1.unite(--p[i], --q[i]);
    }

    rep(i, 0, L) {
        cin >> r[i] >> s[i];
        uf2.unite(--r[i], --s[i]);
    }

    map<pair<int, int> ,int> mp;
    rep(i, 0, N) {
        mp[pair<int, int>(uf1.find(i), uf2.find(i))]++;
    }
    rep(i, 0, N) {
        cout << mp[pair<int, int>(uf1.find(i), uf2.find(i))] << " ";
    }
    cout << endl;

}
