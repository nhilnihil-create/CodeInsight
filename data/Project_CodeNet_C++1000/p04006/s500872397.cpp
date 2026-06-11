#include <iostream>
using namespace std;
typedef long long ll;

const ll INF = 100000000000000;

ll l[2005][2005];

int main()
{
    int n;
    ll x;
    cin >> n >> x;
    ll a[2005];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        l[i][i] = INF;
        for(int j = 1; j <= n; j++) l[i][(i + j) % n] = min(l[i][(i + j - 1) % n], a[(i + j - 1) % n]);
    }
    ll ans = INF;
    for(ll k = 0; k < n; k++){
        ll s = k * x;
        for(int i = 0; i < n; i++){
            s += l[(i + n - k) % n][(i + 1) % n];
        }
        ans = min(ans, s);
    }
    cout << ans << endl;
}
