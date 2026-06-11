#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();
// freopen("input.txt", "r", stdin);

int main() {
    int n, val;
    map<int, int> cnt;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> val;
        cnt[i+1] += val;
    }
    ll ans = 0;
    for(auto& p: cnt) {
        ans += p.second / 2;
        p.second %= 2;
        if (cnt.count(p.first+1) > 0) {
            int mn = min(p.second, cnt[p.first+1]);
            ans += mn;
            p.second -= mn;
            cnt[p.first+1] -= mn;
        }

    }
    cout << ans << endl;
    return 0;
}


