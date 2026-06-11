#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 10;
int a[N];

int main()
{
    int n, L; cin >> n >> L;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int tmp = 0;
    for (int i = 1; i < n; i++) if (a[i] + a[i + 1] >= L) tmp = i;
    if (tmp == 0) return cout << "Impossible\n", 0;
    cout << "Possible\n";
    for (int i = 1; i < tmp; i++) cout << i << " ";
    for (int j = n - 1; j > tmp; j--) cout << j << " ";
    cout << tmp << "\n";

    return 0;
}
