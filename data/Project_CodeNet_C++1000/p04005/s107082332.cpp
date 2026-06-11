#include <bits/stdc++.h>
using namespace std;
#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
using ll = long long;

int main() {
    vector<ll> length(3);
    rep(i, 0, 3) cin >> length[i];
    sort(length.begin(), length.end());
    ll ans = 0;
    if(length[0] % 2 ==1 && length[1] % 2  == 1 && length[2] % 2 == 1){
        ans = length[0] * length[1];
        cout << ans << endl;
        return 0;
    }
    cout << ans << endl;
}