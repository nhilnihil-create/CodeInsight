#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using uint = unsigned int;
using matrix = vector<vector<uint>>;
template <typename T>
using Graph = vector<vector<T>>;
const int MOD = 1e9 + 7;
const pii INI = {INT_MAX, -1};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int a, b, c;
  	cin >> a >> b >> c;
  	cout << (b - a == c - b ? "YES" : "NO") << endl;
    return 0;
}
