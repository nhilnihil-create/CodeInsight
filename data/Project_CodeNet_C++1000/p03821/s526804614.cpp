#include <bits/stdc++.h>
using namespace std;

int main () {
    long long n; cin >> n;

    long long a[n], b[n];
    for (long long i = 0; i < n; i++)
        cin >> a[i] >> b[i];

    long long ans = 0;
    for (long long i = n - 1; i > -1; i--) {
        // if ((a[i] + ans) != 0)
            ans += (b[i] - ((a[i] + ans) % b[i])) % b[i];
        // else 
        //     ans += b[i];
    }
    cout << ans;

}