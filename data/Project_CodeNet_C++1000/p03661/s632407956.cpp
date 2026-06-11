#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;
#define INF 1e9


int main(){
    int n; cin >> n;
    vector<int> a(n);
    ll lsum = 0, rsum = 0;

    rep(i,n) {
        cin >> a[i];
        rsum += a[i];
    }
    lsum += a[0];
    rsum -= a[0];
    
    ll ans = INF;
    for(int i=1; i<n-1; i++){
        lsum += a[i];
        rsum -= a[i];
        ans = min(ans, abs(lsum-rsum));
    }
    if(ans == INF) ans = abs(lsum-rsum);
    cout << ans << endl;
    
}
