#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;



int main() {
    int n; cin >> n;
    ll c,k; cin >> c >> k;
    double count = 1;
    ll ans = 0;
    ll prev;
    vector<ll> t(n);
    rep(i,n) cin >> t[i];
    sort(t.begin(),t.end());
    prev = t[0];
    for(int i = 1; i < n; i ++){
        if(k >= (t[i]-prev)) count ++;
        else{
            prev = t[i];
            ans ++;
            count = 1;
        }
        if(count >= c){
            if(i != n-1) prev = t[i+1];
            ans ++;
            count = 0;
        }
    }
    ans += ((count == 0)?0:1);
    cout << ans;

    return 0;
}









