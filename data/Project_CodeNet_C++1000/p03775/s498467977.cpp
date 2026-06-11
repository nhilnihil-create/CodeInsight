#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int f(int x) {
    int keta = 0;
    while (x) {
        keta++;
        x /= 10;
    }
    return keta;
}

int main() {
    ll n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n%i==0) {
            if (ans==0) ans = max(f(i),f(n/i));
            else ans = min(max(f(i),f(n/i)),ans);
        }
    }
    cout << ans << endl;
    return 0;
}
