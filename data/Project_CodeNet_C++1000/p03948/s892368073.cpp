#include <bits/stdc++.h>
#define err(args...) {}
#ifdef DEBUG
#include "_debug.cpp"
#endif
using namespace std;
using ll = long long;
using ld = long double;
template <typename T> using lim = numeric_limits<T>;
template <typename T> istream& operator>>(istream& is, vector<T>& a) { for(T& x : a) { is >> x; } return is; }
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    cin >> a;
    set<int> seen = {a[0]};
    map<int, int> profits;
    for(int i = 1; i < n; i++) {
        profits[a[i] - *seen.begin()]++;
        seen.insert(a[i]);
    }
    cout << profits.rbegin()->second << endl;
    return 0;
}
