#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int n,x;
    cin >> n >> x;
    vector<ll> a(n); 
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll before = 0;
    for(int i = 0; i < n; i++) {
        before += ll(a[i]);
    }
    if(a[0] > x) {
        a[0] = x;
    }
    for(int i = 0; i < n-1; i++) {
        if(a[i] + a[i+1] > x) {
            a[i+1] = x - a[i];
        }
    }
    ll after = 0;
    for(int i = 0; i < n; i++) {
        after += ll(a[i]);
    }
    cout << before - after << "\n";
    return 0;
}