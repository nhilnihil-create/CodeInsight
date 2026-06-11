#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <map>
using namespace std;
#define ll long long
#define rep(i, s, n) for(int i = s; i < n; i++)
ll MOD = 1e9+7;
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int zero_flag = 0;
    int count = 0;
    map<int, int> mp;
    ll ans = 1;
    rep(i, 0, n) {
        cin >> a[i];
        if(a[i] == 0) {
            count++;
        }
        mp[a[i]]++;
    }

    if(mp[0] >= 2) {
        cout << 0 << endl;
        return 0;
    }
    else if(mp[0]%2 == 1 && n%2 == 0) {
        cout << 0 << endl;
        return 0;
    }

    rep(i, 0, n/2) {
        if(mp[a[i]] != 2 && mp[0] != 1) {
            cout << 0 << endl;
            return 0;
        }
        else {
            ans *= 2;
            ans %= MOD;
        }
    }
    cout << ans << endl;
    return 0;
}