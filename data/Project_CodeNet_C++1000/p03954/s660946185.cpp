#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 10;
int p[N], a[N], n;

bool isval(int x) {
    for (int i = 0; i <= 2 * n; i++) a[i] = (p[i] >= x);
    if (a[n] == a[n-1] || a[n] == a[n+1]) return a[n];
    int l = n-1, r = n+1;
    while (a[l] != a[l-1]) l--;
    while (a[r] != a[r+1]) r++;
    l++, r--;
    if ((r - l + 1) % 2) return a[l-1];
    if (n <= (r+l)/2) return a[l-1];
    else return a[r+1];

}
int main()
{
    cin >> n;
    for (int i = 1; i < 2 * n; i++) cin >> p[i];
    p[0] = p[1], p[2*n] = p[2*n - 1];
    int dw = 1, up = 2 * n - 1;
    while (up - dw > 1) {
        int mid = (up + dw)>>1;
        if (isval(mid)) dw = mid;
        else up = mid;
    }
    cout << dw << "\n";
}
