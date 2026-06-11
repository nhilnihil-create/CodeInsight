#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    long long num = pow(10,9) + 7;
    long long ans = 1;
    cin >> n >> m;

    if (n==m) {
        for (int i=0; i<n; i++){
            ans *= i+1;
            ans %= num;
        }
        ans *= ans;
        ans %= num;
        ans *= 2;
        ans %= num;
    }
    else if (abs(n-m) == 1) {
        for (int i=0; i<n; i++){
            ans *= i+1;
            ans %= num;
        }
        for (int i=0; i<m; i++) {
            ans *= i+1;
            ans %= num;
        }
    }
    else {
        cout << 0 << endl;
        exit(0);
    }
    cout << ans << endl;
}
