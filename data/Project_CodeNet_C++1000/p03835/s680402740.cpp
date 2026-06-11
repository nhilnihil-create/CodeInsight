#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;


void solve() {
    int k, s;
    ll ans = 0;
    int x , y, z;
    cin >> k >> s;
    for (int i = 0; i <= k; ++i) {
        for (int j=0; j <= k; ++j) {
                if ((s - i - j <= k) && (s - i -j >=0)) ++ans;
        }
    }
    cout << ans;

}

int main() {

    solve();
    return 0;
}
