#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k, s = 0;
    cin >> n >> k;
    int l[n];
    for (int i = 0; i < n; i++) cin >> l[i];
    sort(l, l + n);
    for (int i = n - 1; i >= n - k; i--) s += l[i];
    cout << s;
}