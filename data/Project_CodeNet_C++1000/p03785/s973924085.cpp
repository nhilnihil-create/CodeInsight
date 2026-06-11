#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, c, k;
    cin >> n >> c >> k;
    vector<int> t(n);
    rep(i,n) cin >> t[i];
    sort(all(t));
    int ans = 0;
    for(int i = 0; i < n;) {
        ans++;
        int s = i;
        while(i<n && t[i]-t[s] <= k && i - s +1 <= c) ++i;
    }
    
    cout << ans << endl;
    return 0;
}