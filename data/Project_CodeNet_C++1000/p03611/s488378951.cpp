/**
 *    author:  FromDihPout
 *    created: 2020-08-04
**/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    map<int,int> cnt;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x-1]++;
        cnt[x]++;
        cnt[x+1]++;
    }
    
    int ans = 0;
    for (auto i : cnt) {
        ans = max(ans, i.second);
    }
    cout << ans << '\n';
    return 0;
}