#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll A[100002], B[100002];
bool one[100002];
ll n, k;
int main(){
    cin >> n >> k; 
    ll total = 0;
    for (int i = 0; i < n; i ++) {
        cin >> A[i] >> B[i];
        if (A[i] <= k) {
            total += B[i];
            one[i] = 1;
        }else one[i] = 0;
    }
    ll logk = 0, kk = k << 1;
    while (kk >>= 1 > 0) logk ++;
    ll ans = 0;
    for (int i = logk - 1; i >= 0; i --) {
        if ((k >> i) & 1) {
            ll tmp = total;
            for (int j = 0; j < n; j ++) {
                if (one[j] && ((A[j] >> i) & 1) == 1) tmp -= B[j];
            }
            ans = max(ans, tmp);
        } else {
            for (int j = 0; j < n; j ++) {
                if (((A[j] >> i) & 1) == 1 && one[j]) {
                    total -= B[j];
                    one[j] = 0;
                }
            }
        }
    }
    ans = max(ans, total); 
    cout << ans << endl; 
    return 0;
}