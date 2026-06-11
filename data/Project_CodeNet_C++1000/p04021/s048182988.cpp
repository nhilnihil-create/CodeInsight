#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    map<int, int> mp;
    rep(i, n) {
        cin >> a[i];
        mp[a[i]] = i%2;
        b[i] = a[i];
    }

    sort(b.begin(), b.end());

    int ans = 0;
    rep(i, n) {
        if(mp[b[i]] != i%2) {
            ans++;
        }
    }

    if(ans%2 == 0) {
        ans /= 2;
    }   
    /*else {
        ans /= 2;
        ans++;
    }*/

    cout << ans << endl;
    return 0;
}