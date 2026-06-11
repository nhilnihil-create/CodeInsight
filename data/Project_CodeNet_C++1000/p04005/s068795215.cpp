#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define put(i) cout<<fixed<<i<<endl
using namespace std;
using ll = long long;

int main(){
    vector<ll> a(3);
    cin >> a[0] >> a[1] >> a[2];

    sort(a.begin(), a.end());

    if(a[0] * a[1] * a[2] % 2 == 0){
        put(0);
    }else{
        ll ans = abs(a[0] * a[1] * (a[2] / 2 + 1) - a[0] * a[1] * (a[2] / 2));
        ans = min(ans, abs(a[0] * a[1] * (a[2] / 2) - a[0] * a[1] * (a[2] / 2 + 1)));
        put(ans);
    }
}