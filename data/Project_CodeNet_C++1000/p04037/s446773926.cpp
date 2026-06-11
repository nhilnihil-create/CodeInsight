#include <bits/stdc++.h>
using namespace std;
int a[300000];
bool cmp(int a, int b) { return a > b; }
int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n, cmp);
    int x, y;
    for (int i = 1; i <= n + 1; i++) {
        if (a[i] < i) {
            x = y = i - 2;
            break;
        }
    }
    int d1 = a[x + 1] - y;
    int d2 = x + 1;
    while (a[d2] > y) d2++;
    d2 -= x + 1;
    bool f = 0;
    if (d1 % 2 == 0) f = 1;
    if (d2 % 2 == 0) f = 1;
    if (f)
        cout << "First";
    else
        cout << "Second";
    //cout << endl << x << ' ' << y;
    //cout << endl << d1 << ' ' << d2;
}