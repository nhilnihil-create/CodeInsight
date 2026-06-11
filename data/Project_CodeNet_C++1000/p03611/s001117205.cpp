#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll n;
    cin >> n;
    vector<ll> fl(100010, 0);
    rep(i, 0, n){
        ll a;
        cin >> a;
        fl[a]++;
        if(a > 0) fl[a-1]++;
        fl[a+1]++;
    }
    auto ans = *max_element(fl.begin(), fl.end());
    cout << ans << endl;
    return 0;
}