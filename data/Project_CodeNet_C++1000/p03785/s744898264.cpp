#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
    int n,c,k;
    cin >> n >> c >> k;
    vector<int> t(n);
    rep(i,n) cin >> t[i];
    
    sort(t.begin(),t.end());
    ll ans=1,cnt=0,time=t[0];
    rep(i,n){
        if(cnt < c && t[i] - time <= k){
            cnt++;
        }
        else{
            cnt = 1; time= t[i]; ans++;
        }
    }
    cout << ans << endl;
    return 0;
}