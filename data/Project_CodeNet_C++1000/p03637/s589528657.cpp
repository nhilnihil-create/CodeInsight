#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    int two = 0, four = 0;

    int ans = 0;
    rep(i, n) {
        ll a;
        cin >> a;
        if (a % 4 == 0)
            four++;
        else if (a % 2 == 0)
            two++;
    }

    if (n == two || n / 2 <= four + two / 2)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
