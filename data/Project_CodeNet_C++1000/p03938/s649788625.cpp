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
    int N;
    int ansa[20005], ansb[20005];
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        int p;
        cin >> p; --p;
        ansa[p] = p * N + 1;
        ansb[p] = (N - p - 1) * N + i + 1;
    }

    for (int i = 0; i < N; i++) {
        if (i > 0) cout << " ";
        cout << ansa[i];
    }
    cout << endl;

    for (int i = 0; i < N; i++) {
        if (i > 0) cout << " ";
        cout << ansb[i];
    }
    cout << endl;
    return (0);
}