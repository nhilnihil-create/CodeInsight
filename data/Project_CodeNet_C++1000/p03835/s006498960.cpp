#include<iostream>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int k, s;
    cin >> k >> s;

    int mini = min(k, s);
    ll ans = 0;
    for (int z = 0; z <= mini; z++) {
        int t = s - z;
        if (t > k) ans += max(t + 1 - 2 * (t - k), 0);
        else ans += t + 1;
    }

    cout << ans << endl;
}