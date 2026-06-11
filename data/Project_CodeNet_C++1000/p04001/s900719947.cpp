#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n-1; i >= 0; i--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
const int mod = 1e9+7;
const int INF = 2e9;
// const ll INF = 1e12;
const int MAX = 1e6;
// const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

// struct edge {int to, cost;}; // 辺
// vector<edge> graph[MAX]; // 隣接リスト
// bool visited[MAX]; // 訪問状況

int main() {
    // input
    string s;
    cin >> s;
    // solve
    int n = s.size();
    vector<int> x(n);
    rep(i, n) {
        x[i] = s[i] - '0';
    }
    reverse(ALL(x));
    ll sum = 0;
    // if (n == 1) {
    //     sum = x[0];
    // }
    rep(bit, 1<<(n-1)) {
        bitset<10> B = bit;
        sum += x[0];
        ll d = 1;
        rep(i, n-1) {
            if (bit & 1<<i) {
                d *= 10;
            } else {
                d = 1;
            }
            sum += d * x[i+1];
        }
    }
    // output
    cout << sum << endl;
}