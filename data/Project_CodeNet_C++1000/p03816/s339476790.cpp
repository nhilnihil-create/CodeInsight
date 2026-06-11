#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    map<int, int> mp;
    rep(i, n){
        int a;
        cin >> a;
        mp[a]++;
    }
    int cnt = 0;
    for(auto itr = mp.begin(); itr != mp.end(); itr++){
        cnt += itr->second - 1;
    }
    int ans = n - (cnt + 1) / 2 * 2;
    cout << ans << endl;
}