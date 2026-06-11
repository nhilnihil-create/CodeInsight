#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    ll n, k;
    cin >> n >> k;
    vector<ll> ar(100000, 0);

    ll a, b;
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld", &a, &b);
        ar[a] += b;
    }

    ll cnt = 0, ans;
    for (ans = 0; ans < 100000; ans++) {
        cnt += ar[ans];
        if (cnt >= k) break;
    }

    cout << ans << endl;
    
}