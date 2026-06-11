#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    int ans = 1;
    if (n == 1) cout << ans << endl;
    else {
    for (int i = 7; i > 0; i--)
    {
        ans = pow(2, i);
        if (ans <= n) {
            cout << ans << endl;
            break;
        }
    }
}
}