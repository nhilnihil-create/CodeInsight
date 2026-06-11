#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n-1; i >= 0; i--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int mod = 1e9+7;
const int INF = 1e9;
const int MAX = 1e6;

int main() {
    int n;
    cin >> n;
    unordered_set<int> s;
    rep(i, n) {
        int x;
        cin >> x;
        if (s.count(x)) s.erase(x);
        else s.insert(x);
    }
    cout << (int)s.size() << endl;
}