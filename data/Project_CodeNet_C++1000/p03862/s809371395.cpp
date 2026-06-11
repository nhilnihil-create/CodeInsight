#include<bits/stdc++.h>
using namespace std;

int main() {
    long long N, x; cin >> N >> x;
    long long a[N];
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    long long ans = 0;
    for (int i = 1; i < N; i++)
    {
        if(a[i] + a[i-1] > x) {
            ans += a[i] + a[i-1] - x;
            a[i] = max(0LL, x - a[i-1]);
        }
    }

    cout << ans << endl;
}