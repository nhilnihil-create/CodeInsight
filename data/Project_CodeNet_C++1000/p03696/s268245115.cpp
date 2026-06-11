#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    deque<char> que, left, right;
    deque<char> ans;

    int N;
    cin >> N;
    rep(i, N) {
        char a;
        cin >> a;
        ans.push_back(a);
        if (!que.empty() && que.back() == '(' && a == ')')
            que.pop_back();
        else
            que.push_back(a);
    }

    while (!que.empty()) {
        if (que.front() != ')')
            break;
        else
            que.pop_front(), ans.push_front('(');
    }

    while (!que.empty()) {
        if (que.back() != '(')
            break;
        else
            que.pop_back(), ans.push_back(')');
    }

    rep(i, ans.size()) { cout << ans[i]; }
}