#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll K, T;
    cin >> K >> T;
    map<ll, ll> mp;
    ll mx = 0, sum = 0;
    rep(i, 0, T){
        ll a;
        cin >> a;
        sum += a;
        mx = max(mx, a);
    }
    if(mx - (sum-mx) > 1){
        cout << mx - (sum - mx) -1 << endl;
    }else{
        cout << 0 << endl;
    }
    return 0;
}