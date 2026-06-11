#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1000000007; 

int main(){
    int N;
    cin >> N;
    vector<ll> t(N);
    vector<ll> a(N);
    for (int i = 0; i < N; i++) cin >> t[i];
    for (int i = 0; i < N; i++) cin >> a[i];
    
    vector<ll> h(N, 0);
    h[0] = t[0];
    for (int i = 1; i < N; i++) {
        if (t[i-1] < t[i]) h[i] = t[i];
    }
    
    if (h[N-1] > 0 && h[N-1] != a[N-1]) {
        cout << 0 << endl;
        return 0;
    } else {
        h[N-1] = a[N-1];
    }
    
    for (int i = N-2; i >= 0; i--) {
        if (a[i] > a[i+1]) {
            if (h[i] > 0 && h[i] != a[i]) {
                cout << 0 << endl;
                return 0;
            } else {
                h[i] = a[i];
            }
        }
    }
    
    ll ans = 1;
    for (int i = 0; i < N; i++) {
        if (h[i] > 0) {
            if (h[i] > t[i] || h[i] > a[i]) {
                cout << 0 << endl;
                return 0;
            }
            continue;
        } else {
            ans = ans * min(t[i], a[i]) % mod;
        }
    }
    cout << ans << endl;
}