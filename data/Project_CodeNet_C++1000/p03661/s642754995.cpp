#include<bits/stdc++.h>
#define rep(i,a,n) for (int i = a;i < n;i++)
using namespace std;

long long sum = 0, x = 0, ans = 1000000000000000000LL;

int main() {
    int n; cin >> n;
    vector<long long> a(n);
    rep(i, 0, n) {
        cin >> a[i];
        sum += a[i];
    }
    rep(i, 0, n) {
        x += a[i];
        if (i + 1 < n){
            ans = min(ans, abs(sum - 2 * x));
        }
    }
    cout << ans << endl;
}