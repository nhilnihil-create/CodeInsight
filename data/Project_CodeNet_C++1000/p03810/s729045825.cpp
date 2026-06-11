#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 * 1000 + 20; 
int n, a[maxn];

bool solve(bool win) {
    int ha = 0, cnt[2] = {0, 0};
    for (int i = 0; i < n; i++) {
        cnt[a[i] % 2]++;
        if (a[i] == 1)
            ha++;
    }   
    if (cnt[0] % 2)
        return win;
    if (cnt[1] > 1)
        return !win;
    if (ha)
        return !win;
    int g = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2)  
            a[i]--;
        g = __gcd(g, a[i]);
    }   
    for (int i = 0; i < n; i++)
        a[i] /= g;
    return (solve(!win));
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (n == 1)
        return cout << "Second\n", 0;
    cout << (solve(1)? "First\n": "Second\n");
    return 0;
}
