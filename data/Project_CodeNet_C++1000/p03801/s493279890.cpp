#include <algorithm>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

typedef long long ll;
// constexpr ll MOD = 998244353;
constexpr ll MOD = 1000000007;

// struct UnionFind {
//     vector<int> par;
    
//     UnionFind(int N): par(N) {
//         for (int i=0;i<N;i++) par[i] = i;
//     }

//     int root(int x) {
//         if (par[x] == x) return x;
//         else return par[x] = root(par[x]);
//     }

//     void unite(int x, int y) {
//         int rx = root(x);
//         int ry = root(y);
//         if (rx == ry) return;
//         par[rx] = ry;
//     }

//     bool same(int x, int y) {
//         int rx = root(x);
//         int ry = root(y);
//         return rx == ry;
//     }
// };

int main(void) {
    int N;
    vector<ll> a(100010);
    cin >> N;
    for (int i=0;i<N;i++) cin >> a[i];

    map<ll,pair<int,int>,greater<ll>> M;
    for (int i=0;i<N;i++) {
        if (M.find(a[i]) == M.end()) {
            M[a[i]].first = i+1;
            (M[a[i]].second)++;
        } else {
            if (M[a[i]].first > i+1) M[a[i]].first = i+1;
            (M[a[i]].second)++;
        }
    }
    
    ll c = 0LL;
    ll x, xp = 0LL, y, z, yp = 100001, zp;
    vector<ll> b(100010,0LL);
    for (auto itr: M) {
#ifdef DEBUG
        cout << itr.first << ": <" << itr.second.first << "," << itr.second.second << ">" << endl; 
#endif
        x = itr.first, y = min(yp,(ll)itr.second.first), z = itr.second.second;
        if (xp) if (xp-x > 1) {
            b[yp] += (xp-x-1)*c;
        }
        c += z;
        b[y] += c;
        xp = x, yp = y, zp = z;
    }
    if (xp) {
        b[yp] += (xp-1)*c;
    }

    for (int i=1;i<=N;i++) {
        cout << b[i] << endl;
    }

    return 0;
}
