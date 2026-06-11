#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    int l[55];
    rep(i, N) { cin >> l[i]; }
    sort(l, l + N);
    reverse(l, l + N);
    int total = 0;
    rep(i, K) { total += l[i]; }
    cout << total << endl;
}