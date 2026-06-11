#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

ll h, w, n;
vector<pair<ll, ll>> c;

int in(ll a, ll b) {
    if (a < 0 || a >= h || b < 0 || b >= w) return -1;
    
    ll l = 0, r = n;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        //cout << c[mid].first * 1000000000 + c[mid].second << endl;
        
        if (c[mid].first * 1000000000 + c[mid].second <= a * 1000000000 + b) l = mid;
        else r = mid;
    }
    if (c[l].first * 1000000000 + c[l].second == a * 1000000000 + b) return 1;
    else return 0;
}

int main(void){
    cin >> h >> w >> n;
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        a--;  b--;
        c.emplace_back(a, b);
    }
    sort(c.begin(), c.end());
    
    ll ans[10] = {};
    for (int i = 0; i < n; i++) {
        for (int p = 0; p < 9; p++) {
            int bl = 0;
            for (int q = 0; q < 9; q++) {
                if (in(c[i].first - 2 + p / 3 + q / 3, c[i].second - 2 + p % 3 + q % 3) == 1) bl++;
                else if (in(c[i].first - 2 + p / 3 + q / 3, c[i].second - 2 + p % 3 + q % 3) == -1) {
                    bl = -1;  break;
                }
            }
            //cout << i << " (" << c[i].first << ", " <<c[i].second  << ") " << p/3 << " " << p%3 <<" " <<bl << endl;
            if (bl != -1) ans[bl]++;
        }
    }
    
    
    //for (int i = 1; i < 10; i++) cout << ans[i] << endl;
    
    ll sum = 0;
    for (int i = 1; i < 10; i++) {
        ans[i] /= i;
        sum += ans[i];
    }
    
    cout << (h - 2) * (w - 2) - sum << endl;
    for (int i = 1; i < 10; i++) cout << ans[i] << endl;
    
    
    
}
