#include<bits/stdc++.h>
using namespace std;

#define LL long long
int cnt[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, x, mx = 0, mn = 1e9, m, y; cin >> n; m = n;
    while(n--) {
        cin >> x;
        ++cnt[x];
        mx = max(x, mx);
        mn = min(x, mn);
    }    
    n = m;

    if(mx != mn && mx != mn + 1) {
        cout << "No"; return 0;
    }

    if(mn == mx && ((mn == n - 1 && mx == n-1) || (mx * 2 <= n))) {
        cout << "Yes"; return 0;
    }

    x = cnt[mn], y = cnt[mx];
    if(x + 1 > mx  || x + y / 2 < mx) {
        cout << "No"; return 0;
    }
    cout << "Yes";
}