/**
*    created: 21.06.2020 01:20:27
**/
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(a) (a).begin(),(a).end()
#define mod 1000000007
#define pi acos(-1.0)
using namespace std;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    map<int,int> mp;
    rep(i,n) {
        int a, b;
        cin >> a >> b;
        mp[a] += b;
    }
    int now = 0;
    for (auto itr = mp.begin(); itr != mp.end(); itr++) {
        now += itr->second;
        if (now >= k) {
            cout << itr->first << endl;
            return 0;
        }
    }
    return 0;
}
