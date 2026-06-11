#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+100;

int n, a[N];

bool solve() {
    if(n == 1) {
        return a[0] & 1;
    }
    int hav1 = 0, odd = 0, even = 0, sum = 0;
    for(int i = 0 ; i < n ; i++ ) {
        if(a[i] & 1) odd++;
        else even++;
        if(a[i] == 1)hav1++;
        sum = (sum + a[i]) % 2;
    }
    if(hav1) {
        return !((sum - n) & 1);
    }
    if(odd == n) return 1;
    if(even == 1) return 0;
    if(odd > 1) return !(even & 1);
    if(even & 1) return 0;
    for(int i = 0 ; i < n ; i++ ) {
        if(a[i] & 1) if(a[i] > 1)a[i]--;
    }
    int gc = a[0];
    for(int i = 0 ; i < n ; i++ ) {
        gc = __gcd(a[i], gc);
    }
    for(int i = 0 ; i < n ; i++ ) {
        a[i] /= gc;
    }
    return !solve();
}

int main () {
    cin >> n;
    for(int i = 0 ; i < n ; i++ ) {
        cin >> a[i];
    }
    cout << ((!solve()) ? "First" : "Second") << '\n';
}
