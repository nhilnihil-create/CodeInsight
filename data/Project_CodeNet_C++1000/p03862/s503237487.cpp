#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int N,x;
    cin >> N >> x;
    vector<int>a(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for(int i = 0; i < N-1; i++) {
        if(a[i]+a[i+1] > x) {
            ans+=(a[i]+a[i+1])-x;
            a[i+1] = max(a[i+1]-(a[i]+a[i+1]-x),0LL);
        }
    }
    cout << ans << endl;
}