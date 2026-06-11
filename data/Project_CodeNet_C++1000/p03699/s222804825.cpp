#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n-1; i >= 0; i--)
#define all(x) x.begin(), x.end()
using ll = long long;
using pii = pair<int, int>;
const int mod = 1e9+7;

int main() {
    int n;
    cin >> n;
    int s[n];
    int score = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    rep(i, n) {
        cin >> s[i];
        score += s[i];
        if (s[i] % 10 != 0) pq.push(s[i]);
    }
    if (score % 10 == 0) {
        if (pq.empty()) {
            score = 0;
        } else {
            score -= pq.top();
            pq.pop();
        }
    }
    cout << score << endl;
}