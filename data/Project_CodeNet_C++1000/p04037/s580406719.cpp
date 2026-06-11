#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;
int a[N];

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n), reverse(a, a + n);
    int i = 1;
    while (i + 1 <= a[i]) i++;
    int h = a[i - 1] - i, w = 0;
    while (a[i + w] == i) w++;
    h %= 2, w %= 2;
    cout << ((w|h) ? "First" : "Second") << "\n";

    return 0;
}
