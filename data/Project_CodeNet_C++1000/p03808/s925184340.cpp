/**
 *   @FileName	a.cpp
 *   @Author	kanpurin
 *   @Created	2020.06.22 22:36:27
**/

#include "bits/stdc++.h" 
using namespace std; 
typedef long long ll;

int main() {
    ll n; cin >> n;
    vector<ll> a(n),b(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % (n * (n + 1) / 2) != 0) {
        puts("NO");
        return 0;
    }
    ll k = sum / (n * (n + 1) / 2);
    for (int i = 0; i < n; i++) {
        b[i] = a[(i+1)%n] - a[i];
        b[i] -= k;
        b[i] = -b[i];
    }
    for (int i = 0; i < n; i++) {
        if (b[i] < 0 || b[i] % n != 0) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}