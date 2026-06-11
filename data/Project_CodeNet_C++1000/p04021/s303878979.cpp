#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B;
    for (int i = 0; i < N; i++) cin >> A[i];
    B = A;
    sort(B.begin(), B.end());
    int ans = 0;
    for (int i = 0; i < N; i += 2) {
        auto it = lower_bound(B.begin(), B.end(), A[i]);
        int t = distance(B.begin(), it);
        if (t%2 == 1) ans++;
    }
    cout << ans << endl;
}