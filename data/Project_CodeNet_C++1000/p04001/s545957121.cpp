#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    ll ans = 0;
    for(int i = 0; i < (1 << n-1); ++i){
        ll a = 0;
        for(int j = 0; j < n; ++j){
            a = a * 10 + s[j] - '0';
            // cout << a << endl;
            if(i>>j & 1){
                ans += a;
                // cout << ans << endl;
                a = 0;
            }
        }
        ans += a;
    }
    cout << ans << endl;
    return 0;
}