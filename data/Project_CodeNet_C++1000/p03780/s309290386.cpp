#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n)cin >> a[i];
    sort(a.begin(), a.end());
    int l = -1;
    int r = n;
    while(l + 1 < r){
        int x = (l + r) / 2;
        vector<int> dp(k+1, 0);
        dp[0] = 1;
        rep(i, n){
            if(i == x)continue;
            for(int j = k-1; j >= 0; j--){
                if(dp[j] == 1){
                    dp[min(j+a[i], k)] = 1;
                }
            }
        }
        bool v = true;
        for(int i = max(k-a[x], 0); i < k; i++){
            if(dp[i] == 1)v = false;
        }
        if(v)l = x;
        else r = x;
    }
    cout << l + 1 << endl;
}