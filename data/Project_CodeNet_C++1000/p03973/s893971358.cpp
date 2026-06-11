#include <bits/stdc++.h>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using namespace std;
typedef long long ll;
typedef pair<int, int> pint;

const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;


int main() {
    int n; cin >> n;
    vector<int> a(n); rep(i, n) cin >> a[i];
    ll ans = a[0]-1;
    int num = 2;
    for (int i = 1; i < n; ++i) {
        int p = a[i] / num;
        int q = a[i] % num;
        if (a[i] == num) {
            num++;
        } else if (q > 0) {
            ans += p;
        } else {
            ans += p-1;
        }
    }

    cout << ans << endl;

    return 0;
}


    
