#include<bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
using namespace std;
using ll = long long;
typedef vector<int> vi;


signed main() {
    int n;
    cin >> n;
    vi a(3*n);
    rep(i, 3*n) cin >> a[i];
    sort(a.begin(), a.end(), greater<int>());
    int ans = 0;

    rep(i, n){
        ans += a[2*i +1];
    }

    cout << ans << endl;
}