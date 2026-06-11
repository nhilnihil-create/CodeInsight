#include <bits/stdc++.h> 
using namespace std;
using ll = long long;

void solve() {
    int N;
    cin >> N;
    vector<ll> a(N),b(N);
    for(int i=0;i<N;i++) cin >> a[i] >> b[i];
    ll cnt=0;
    for(int i=N-1;i>=0;i--) {
        a[i]+=cnt;
        cnt+=(a[i]+b[i]-1)/b[i]*b[i]-a[i];
    }
    cout << cnt << "\n"; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}