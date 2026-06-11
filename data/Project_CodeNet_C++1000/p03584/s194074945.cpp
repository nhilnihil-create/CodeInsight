#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
typedef long long ll;

int main(void){
    ll n, k, a[100010], b[100010];
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
    
    vector<int> bit;
    bool d[35] = {};
    ll ans = 0;
    int up = -1;
    for (int i = 30; i >= 0; i--) {
        if (k & (1 << i)) {
            bit.push_back(i);
            d[i] = true;
            up = max(up, i);
        }
    }
    
    for (int i = 0; i < bit.size(); i++) {
        ll tmp = 0;
        for (int j = 0; j < n; j++) {
            bool can = true;
            if (a[j] > k) can = false;
            for (int l = up; l > bit[i]; l--) {
                if (!d[l] && a[j] & (1 << l)) can = false;
            }
            if (a[j] & (1 << bit[i])) can = false;
            if (can) tmp += b[j];
        }
        ans = max(ans, tmp);
        //cout << bit[i] << " " << tmp << endl;
    }
    
    ll last = 0;
    for (int j = 0; j < n; j++) {
        bool can = true;
        if (a[j] > k) can = false;
        for (int l = up; l >= 0; l--) {
            if (!d[l] && a[j] & (1 << l)) can = false;
        }
        if (can) last += b[j];
    }
    ans = max(ans, last);
    //cout << -1 << " " << last << endl;
        
    cout << ans << endl;
    
    
}
