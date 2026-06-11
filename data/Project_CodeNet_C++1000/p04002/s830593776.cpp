#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
const ll N = 123456;

pair < ll , ll > a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll h , w , n;

    cin >> h >> w >> n;

    rep(i , 1 , n) cin >> a[i].first >> a[i].second;

    map < pair < ll , ll > , ll > res;

    rep(p , 1 , n) {
        pair < ll , ll > k = a[p];
        for(ll i = k.first - 2 ; i <= k.first; i++) {
            for(ll j = k.second - 2 ; j <= k.second ; j++) {
                if(i >= 1 && j >= 1 && i + 2 <= h && j + 2 <= w) {
                    if(res.find({i , j}) == res.end()) {
                        res[make_pair(i , j)] = 1;
                    }
                    else {
                        res[make_pair(i , j)]++;
                    }
                }
            }
        }
    }

//    cout << endl;
//
//    for(auto j : res) {
//        cout << j.first.first << " " << j.first.second << "      " << j.second << endl;
//    }

    ll total = (h - 2) * (w - 2);

    vector < ll > ans;
    ans.resize(10);

    for(ll i = 0 ; i < 10 ; i++) {
        ans[i] = 0;
    }

    for(auto j : res) {
        if(j.second <= 9) {
            ans[j.second]++;
        }
    }

    ll sum = 0;

    for(auto j : ans) sum += j;

    ans[0] = total - sum;

    for(auto j : ans) cout << j << endl;
    return 0;
}
