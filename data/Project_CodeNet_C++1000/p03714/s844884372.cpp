/**
 *    author:  FromDihPout
 *    created: 2020-07-28
**/

#include <bits/stdc++.h>
using namespace std;


const long long INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(3 * n);
    for (int i = 0; i < 3 * n; i++) {
        cin >> a[i];
    }
    
    vector<long long> pref(n + 1), suff(n + 1);
    priority_queue<int> next;
    for (int i = 0; i < n; i++) {
        pref[0] += a[i];
        next.push(-a[i]);
    }
    int index = 1;
    for (int i = n; i < 2 * n; i++) {
        pref[index] = pref[index - 1];
        int smallest = -next.top();
        if (a[i] > smallest) {
            next.pop();
            next.push(-a[i]);
            pref[index] -= smallest;
            pref[index] += a[i];
        }
        index++;
    }
    
    next = priority_queue <int>();
    for (int i = 3 * n - 1; i >= 2 * n; i--) {
        suff[0] += a[i];
        next.push(a[i]);
    }
    index = 1;
    for (int i = 2 * n - 1; i >= n; i--) {
        suff[index] = suff[index-1];
        int largest = next.top();
        if (a[i] < largest) {
            next.pop();
            next.push(a[i]);
            suff[index] -= largest;
            suff[index] += a[i];
        }
        index++;
    }
    
    long long ans = -INF;
    for (int i = 0; i <= n; i++) {
        ans = max(ans, pref[i] - suff[n-i]);
    }
    cout << ans << '\n';
    
    return 0;
}