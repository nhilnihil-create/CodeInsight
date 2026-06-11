#include <bits/stdc++.h>

using namespace std;
const int N = 2e4 + 10;
int a[N], b[N];
int main()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i++) a[i] = i * n, b[i] = (n - i + 1) * n;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        a[x] += i - 1;
    }
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << "\n";
    for (int i = 1; i <= n; i++) cout << b[i] << " ";
    cout << "\n";

    return 0;
}
