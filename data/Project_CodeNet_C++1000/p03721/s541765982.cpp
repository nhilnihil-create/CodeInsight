/**
 *    author:  FromDihPout
 *    created: 2020-07-26
**/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    long long n, k;
    cin >> n >> k;
    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a[i] = {x, y};
    }
    sort(a.begin(), a.end());
    
    long long added = 0;
    for (int i = 0; i < n; i++) {
        added += a[i].second;
        if (added >= k) {
            cout << a[i].first << '\n';
            break;
        }
    }
    return 0;
}