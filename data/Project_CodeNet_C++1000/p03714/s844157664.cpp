#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int main() {
    int n;
  	cin >> n;
    vector<long long> v(3 * n);
  	for (int i = 0; i < 3 * n; ++i) cin >> v[i];
    vector<long long> ans(n + 1);
    long long left(0), right(0);
    priority_queue<long long> min_q;
    priority_queue<long long, vector<long long>, greater<long long>> max_q;
    for (int i = 0; i < n; ++i) {
        max_q.push(v[i]);
        min_q.push(v[i + 2 * n]);
        left += v[i];
        right += v[i + 2 * n];
    };
    ans[0] = left;
    ans.back() = -right;
    for (int i = n; i < 2 * n; ++i) {
        max_q.push(v[i]);
        left += v[i] - max_q.top();
        max_q.pop();
        ans[i-n+1] += left;
        min_q.push(v[3 * n - 1 - i]);
        right += v[3 * n - i - 1] - min_q.top();
        min_q.pop();
        ans[2 * n - i - 1] -= right;
    }
    long long res(-1e14);
    for (const long long& i: ans) res = max(res, i);
    cout << res;
    return 0;
};
