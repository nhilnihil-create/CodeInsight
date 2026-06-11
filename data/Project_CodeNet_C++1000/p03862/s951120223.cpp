#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ll N,x;
    cin >> N >> x;
    ll last = 0;
    ll ans = 0;
    for(int i=0;i<N;i++){
        ll a;
        cin >> a;
        if(last + a > x){
            ans += (last+a-x);
            a = x-last;
        }
        last = a;
    }
    cout << ans << endl;

    return 0;
}