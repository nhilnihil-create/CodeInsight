#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int n, ans = 0;
    cin >> n;
    int p[n+1];
    for (int i = 1; i <= n; i++) {
        scanf( "%d", &p[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (p[i] == i) {
            ans++;
            i++;
        }
    }
    cout << ans << endl;
    
    return 0;
}