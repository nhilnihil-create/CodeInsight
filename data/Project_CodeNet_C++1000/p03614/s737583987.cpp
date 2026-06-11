#include <bits/stdc++.h>


using namespace std;


const int MAXN = 100 * 1000 + 123;








int n, p[MAXN];

int main() {
    cin >> n;
    int cnt = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        if (p[i] != i)
            ans += (cnt + 1) / 2, cnt = 0;
        else
            cnt++;
    }
    ans += (cnt + 1) / 2;
    cout << ans;
    return 0;
}