#include <iostream>
#include <bitset>
using namespace std;
typedef long long ll;
const ll INF = 1LL<<60;

int main() {
    int N, K; cin >> N >> K;
    int a[N];
    for (int i = 0; i < N; i++) cin >> a[i];

    ll ans = INF;
    for (int bit = 0; bit < (1<<N); bit++) {
        int t = bitset<15>(bit).count();
        if (t < K) continue;
        int highest = a[0];
        ll cost = 0;
        for (int i = 1; i < N; i++) {
            if ((bit >> i) & 1 && a[i] <= highest) {
                cost += ++highest - a[i];
            } else {
                highest = max(highest, a[i]);
            }
        }
        ans = min(ans, cost);
    }
    cout << ans << endl;
    return 0;
}