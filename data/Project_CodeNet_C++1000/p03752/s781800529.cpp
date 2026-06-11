#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <cmath>
#include <bitset>
#include <climits>

using namespace std;

#define ll long long

int main(void){
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0;i < n;++i)    cin >> a[i];

    int bits_max = (int)pow(2.0, (double)n);
    ll ans = LLONG_MAX;
    for(int bits = 0;bits < bits_max;++bits){
        if(bitset<16>(bits).count() >= k){
            ll hight_max = 0;
            ll cost = 0;

            for(int i = 0;i < n;++i){
                if(bits >> i & 1 && hight_max >= a[i]){
                    cost += hight_max + 1LL - a[i];
                    hight_max = hight_max + 1LL;
                }
                hight_max = max(hight_max, a[i]);
                // cout << i << " " << hight_max << endl;
                // cout << cost << endl;
            }

            ans = min(ans, (ll)cost);
        }
    }

    cout << ans << endl;

    return 0;
}