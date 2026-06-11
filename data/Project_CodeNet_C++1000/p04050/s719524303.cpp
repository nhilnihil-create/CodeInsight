///#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
///#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,mmx,popcnt,avx,avx2,tune=native")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

/*
    zet:
        find_by_order(k): k-stat [k > 0]
        order_of_key(k) : {el < k}

    gp_hash_table<key, val, custom_hash>

    rope<T>:
        iterators: mutable_begin, ..
        methods  : erase, insert, substr, ..
*/

#define all(x) (x).begin(), (x).end()
#define size(x) (int)((x).size())
#define em_back emplace_back

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template<typename T>
using zet = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

mt19937 eng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1e5 + 4;

int n, m, a[N], b[N];
vector<int> odd;

void read() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
        if (a[i] & 1) {
            odd.em_back(i);
        }
    }
}

void write(int id) {
    for (int i = 0; i < m; ++i) {
        cout << a[i] << " ";
    }
    cout << "\n" << id << "\n";
    for (int i = 0; i < id; ++i) {
        cout << b[i] << " ";
    }
    cout << "\n";
}

void solve() {
    read();

    if (size(odd) > 2) {
        cout << "Impossible\n";
        return;
    }

    if (size(odd)) {
        swap(a[0], a[odd[0]]);
        swap(a[m - 1], a[odd.back()]);
    }

    int id = 0;
    if(m == 1) {
        b[id++] = 1;
        if (a[0] > 1) {
            b[id++] = a[0] - 1;
        }
    } else {
        for (int i = 0; i < m; ++i) {
            if (i == 0) {
                b[id++] = a[i] + 1;
            } else {
                b[id++] = a[i];
            }
        }

        if (a[m - 1] > 1) {
            b[id - 1]--;
        } else {
            --id;
        }
    }

    write(id);
}

int main() {
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);

    int z = 1;
    /// cin >> z;

    while (z--) {
        solve();
    }

    return 0;
}
