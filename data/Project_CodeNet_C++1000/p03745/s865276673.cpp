#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>
#include <cassert>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    bool up_flg = false;
    bool dn_flg = false;
    int ans = 1;
    rep(i, n-1) {
        if (a[i] == a[i+1]) continue;
        if (a[i] < a[i+1]) {
            if (dn_flg) {
                dn_flg = false;
                ++ans;
            }
            else if (!up_flg) {
                up_flg = true;
            }
        }
        if (a[i] > a[i+1]) {
            if (up_flg) {
                up_flg = false;
                ++ans;
            }
            else if (!dn_flg) {
                dn_flg = true;
            } 
        }
        //cout << i << " " << ans << " " << dn_flg <<" " << up_flg << endl;
    }
    cout << ans << endl;
    return 0;
}
