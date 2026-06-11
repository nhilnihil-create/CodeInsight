#include <bits/stdc++.h>
using namespace std;
#define lp(i, x, n) for (int i = x; i < (int)n; ++i)
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()
#define ll long long
#define N 123451

int n;
ll pre[100001 * 3], en[100001 * 3], el[100001 * 3];
priority_queue<int> l1, l2;

int main() {

        cin >> n;
        lp (i, 0, n * 3) {
                cin >> el[i];
        }
        pre[0] = el[0];
        l1.push(-el[0]);
        for (int i = 1; i < n; i++) pre[i] = el[i] + pre[i - 1], l1.push(-el[i]);
        for (int i = n; i < n * 2; i ++) {
                l1.push(-el[i]);
                pre[i] = pre[i - 1] + el[i] + l1.top();
                l1.pop();
        }
        en[3 * n - 1] = el[3 * n - 1];
        l2.push(el[3 * n - 1]);
        for (int i = 3 * n - 2; i >= 2 * n; i--) en[i] = el[i] + en[i + 1], l2.push(el[i]);
        for (int i = 2 * n - 1; i >= n; i--) {
                l2.push(el[i]);
                en[i] = en[i + 1] + el[i] - l2.top();
                l2.pop();
        }
        ll ans = -1e18;
        for (int i = n - 1; i < 2 * n; i++) {
                ans = max(ans, pre[i] - en[i + 1]);
        }
        cout << ans;
        return 0;
}


/*
long long
constrain N
*/
