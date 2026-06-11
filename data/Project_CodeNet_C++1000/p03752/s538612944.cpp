#include<bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i < (int)(n);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
int main(){
    int n,k;
    cin >> n >> k;
    vector<ll>a(n);
    rep(i,n)cin >> a[i];
    ll ans = 1LL << 60;
    for(int i = 0;i < 1 << n;i++){
        ll cnt = 0;
        ll tallest = 0;
        ll sum = 0;
        rep(j,n){
            if(1 & i >> j){
                cnt++;
                if(tallest >= a[j]){
                    tallest++;
                    sum += tallest - a[j];
                }
                
            }
            tallest = max(tallest,a[j]);
        }
        if(cnt >= k)ans = min(sum,ans);
        //cout << ans << endl;
    }
    int x = 0;
    cout << ans << endl;
    return 0;
}