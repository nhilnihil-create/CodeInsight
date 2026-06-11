#include <bits/stdc++.h>


using namespace std;


const int MAXN = 100 * 1000 + 23;








int n, a[MAXN];


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    int mx = *max_element(a, a + n), mn = *min_element(a, a + n), x = count(a, a + n, mx), y = count(a, a + n, mn);
    if (mx - mn > 1) return cout << "No", 0;
    if (mx == mn) return cout << ((mx <= n / 2 || mx == n - 1)? "Yes": "No"), 0;
    if (mx >= y + 1 && mx <= y + x / 2)
        return cout << "Yes", 0;
    cout << "No";
    return 0;
}