#include <iostream>
#include <algorithm>
using namespace std;

int a[109];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        int p; cin >> p;
        a[p]++;
        mx = max(mx, p);
    }
    for (int i = 0; i <= mx; i++) {
        int t = max(i, mx - i);
        if (a[t] <= 0) {
            cout << "Impossible" << '\n';
            return 0;
        }
        a[t]--;
    }
    for (int i = 1; i <= (mx + 1) / 2; i++)
        if (a[i] > 0) {
            cout << "Impossible" << '\n';
            return 0;
        }
    cout << "Possible" << '\n';
    return 0;
}
