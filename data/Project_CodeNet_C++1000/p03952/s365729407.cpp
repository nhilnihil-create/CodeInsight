#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using Pi = pair<int, int>;
using Pl = pair<ll, ll>;
using vint = vector<int>;
template<typename T> using uset = unordered_set<T>;
template<typename T1, typename T2> using umap = unordered_map<T1, T2>;

constexpr int INF = (1 << 30) - 1;
constexpr ll LLINF = 1LL << 60;
constexpr int dy[] = {1, 0, -1, 0, 1, -1, -1, 1};
constexpr int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
constexpr char el = '\n';

template<typename T> T lcm(T a, T b) { return (a / gcd(a, b) * b); }

int main() {
    int N, X;
    bool flag[200005] = {};
    cin >> N >> X;

    vint vec(2 * N - 1, 0);
    
    if (X == 1 || X == 2 * N - 1) {
        cout << "No" << el;
        return (0);
    }

    cout << "Yes" << el;
    if (N == 2) {
        cout << 1 << el << 2 << el << 3 << el;
        return (0);
    }
    
    int center = N - 1;
    if (X == 2) {
        vec[center] = 2;
        vec[center + 1] = 1;
        vec[center + 2] = 3;
        vec[center - 1] = 4;
        fill_n(flag + 1, 4, true);
    } else {
        vec[center] = X;
        vec[center + 1] = X + 1;
        vec[center + 2] = X - 1;
        vec[center - 1] = X - 2;
        fill_n(flag + X - 2, 4, true);
    }
    
    int cnt = 1;
    for (int i = 0; i < 2 * N - 1; i++) {
        if (vec[i]) {
            cout << vec[i] << el;
            continue;
        }
        while (flag[cnt]) cnt++;
        vec[i] = cnt++;
        cout << vec[i] << el;
    }
    
    return (0);
}