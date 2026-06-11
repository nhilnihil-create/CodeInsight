#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<bool> r(8, false);
    int n, m = 0, a;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a < 3200) r[a/400] = true;
        else m++;
    }
    int ans = 0;
    ans += count(r.begin(), r.end(), true);
    int ansma = ans + m;
    int ansmi = max (ans, 1);
    printf ("%d %d", ansmi, ansma);
}