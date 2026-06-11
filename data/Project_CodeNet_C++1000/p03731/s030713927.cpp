#include<bits/stdc++.h>
using namespace std;
#define ll long long
const long long INF = 1LL << 60;
using Graph = vector<vector<int>>;

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

inline int gcd(int a, int b) { if (a%b == 0) { return b; } else { return gcd(b, a%b); } }

int main() {
    int n;
    int t;
    cin >> n >> t;
    vector<int> a(n);
    ll total = 0;
    int delta = 0;
    cin >> a[0];
    for (int i = 1; i < n; i++) {
        cin >> a[i];
        delta = a[i] - a[i - 1];
        if (delta < t) {
            total += delta;
        } else {
            total += t;
        }
    }
    total += t;

    cout << total << endl;
    return 0;
}