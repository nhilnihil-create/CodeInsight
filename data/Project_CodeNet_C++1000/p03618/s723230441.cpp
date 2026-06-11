#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    string S; cin >> S;
    map<int, ll> count;
    rep(i, S.size()){
        int idx = (int)(S[i] - 'a');
        count[idx]++;
    }
    ll ans = 1;
    for(int i = 0;i < 25; i++) {
        for(int j = i+1;j < 26;j++) {
            ans += count[i] * count[j];
        }
    }
    cout << ans << endl;
    return 0;
}
