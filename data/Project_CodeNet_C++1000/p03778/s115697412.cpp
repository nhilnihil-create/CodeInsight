#include <bits/stdc++.h>
using namespace std;

int main() {
    int w, a, b;
    cin >> w >> a >> b;
    int ans = 0;
    if (a > b) swap(a, b);
    if (a+w >= b) ans = 0;
    else ans = b - a - w;
    cout << ans << endl;
}