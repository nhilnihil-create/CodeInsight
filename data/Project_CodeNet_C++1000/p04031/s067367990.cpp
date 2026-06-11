#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

int n;
int a[1000];
void solve(){
    cin >> n;
    for(int i=0;i<n;++i) {
        cin >> a[i];
    }
    auto cal = [&](int x) {
        ll f = 0;
        for(int i=0;i<n;++i)
            f+=(a[i]-x)*(a[i]-x);
        return f;
    };
    ll ans = 1e12;
    for(int x = -100 ; x <= 100 ; ++x) {
        ans = min(ans, cal(x));
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t =1;
    while(t--)
        solve();
    return 0;
}

