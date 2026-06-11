#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    int nn = 3 * n;
    vector<int> v(3 * n, 0);
    for (int i = 0; i < 3 * n; i++) {
        cin >> v[i];
    }

    vector<long long int> p1(3 * n, 0), p2(3 * n, 0);
    priority_queue<int> pq;
    long long int s = 0;
    long long int m = 0;
    for (int i = 0; i < 3 * n; i++) {
        s += v[i];
        pq.push(-v[i]);
        if (pq.size() > n) {
            s += pq.top();
            pq.pop();
        }
        m = max(m, s);
        p1[i] = m;
    }
    while (pq.size() > 0) pq.pop();
    s = 0;
    m = 0;
    bool flag = true;
    for (int i = nn - 1; i >= 0; i--) {
        s += v[i];
        pq.push(v[i]);
        if (pq.size() > n) {
            s -= pq.top();
            pq.pop();
        }
        if (nn - 1 - i + 1 >= n && (flag || s < m)) {
            m = s;
            flag = false;
        }
        p2[i] = m;
    }
    long long int res = 0;
    flag = true;
    for (int i = n - 1; nn - 1 - (i + 1) + 1 >= n; i++) {
        if (flag || p1[i] - p2[i + 1] > res) {
            res = p1[i] - p2[i + 1];
            flag = false;
        }
    }
    cout << res << endl;
}
