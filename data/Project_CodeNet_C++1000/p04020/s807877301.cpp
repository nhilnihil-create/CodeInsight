#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long int ans = 0;
    cin >> n;
    int a[n+1] = {0};
    for(int i = 0; i < n; ++i) cin >> a[i];
    long long int sum = 0;
    for(int i = 0; i < n+1; ++i) {
        if(a[i] == 0) {
            ans += sum/2;
            sum = 0;
        } else sum += a[i];
    }
    cout << ans << '\n';

    return 0;
}
