#include <bits/stdc++.h>
using namespace std;
int main () {
    int N;
    cin >> N;
    vector<long long> a(N+1, 0);
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        a[i] += a[i-1];
    }
    long long ans;
    for (int i = 1; i+1 <= N; i++) {
        long long x = a[i];
        long long y = a[N]-a[i];
        if (i == 1) {
            ans = abs(x-y);
        }
        else {
            ans = min(ans, abs(x-y));
        }
    }
    cout << ans << endl;
}