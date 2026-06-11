#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    int A[n];
    rep(i, n) {
        int a;
        cin >> a;
        a--;
        A[i] = a;
    }

    int ans = 0;
    rep(i, n) if (i == A[A[i]]) ans++;

    cout << ans / 2 << endl;
    return 0;
}
