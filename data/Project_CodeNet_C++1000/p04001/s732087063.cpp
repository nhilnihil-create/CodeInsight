#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

int main() {
    string s;
    cin >> s;
    int n=s.size()-1;
    ll ans=0;
    for (int bit = 0; bit < (1<<n); ++bit) {
        ll sum = 0;
        ll pr = 0;
        for (int i = 0; i < n+1; ++i) {
            pr *= 10;
            //-'0'で数字から数値へ変換
            pr += s[i] - '0';
            if(i==n){
                sum += pr;
                break;
            }
            if (1 & (bit>>i)) {
                sum += pr;
                pr = 0;
            }
        }
        ans+=sum;
    }
    cout << ans << "\n";
    return 0;
}