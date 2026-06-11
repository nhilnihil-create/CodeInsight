#include <bits/stdc++.h>
using namespace std;
int a[100050], n, s;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a + n);
    for (int i = 0; i < n - 1; i++) if (a[i] == a[i + 1]) s++;
    cout << (s % 2 == 0 ? n - s : n - s - 1) << endl;
}