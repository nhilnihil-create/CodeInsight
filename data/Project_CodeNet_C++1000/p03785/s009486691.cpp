#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n, c, k;
    cin >> n >> c >> k;
    vector<int> t(n);
    rep(i, n)cin >> t[i];
    sort(t.begin(), t.end(), greater<int>());
    int ans = 1;
    int cnt = 0;
    int end = t[0];
    rep(i, n){
        if(end - t[i] <= k && cnt < c){
            cnt++;
        }else{
            cnt = 1;
            end = t[i];
            ans++;
        }
    }
    cout << ans << endl;
}