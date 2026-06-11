#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N;
    cin >> N;
    vector<long long> a(N);
    for (long long i = 0; i < N; i++) {
        cin >> a[i];
    }
    long long ans = 0;
    for (long long i = 0; i < N; i++) {
        if (a[a[i] - 1] == i + 1) {
            ans++;
        }
    }

    cout << ans / 2 << endl;
    return 0;
}
