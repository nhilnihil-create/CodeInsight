#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n;
    cin >> n;
    vector<ll>a(n);
    for(ll i=0;i<n;i++) cin >> a[i];
    sort(a.begin(),a.end());
    vector<ll>cnt;
    ll x=0,ok=1;
    for(ll i=1;i<n;i++){
        if(a[i]==a[i-1]){
            if(ok==1) cnt.push_back(0);
            ok=0;
            cnt[x]++;
        }else{
            if(ok==0) x++;
            ok=1;
        }
    }
    ll ans=n;
    for(ll i=0;i<cnt.size();i++){
        while(cnt[i]>0){
            if(cnt[i]>=2){
                cnt[i]-=2;
                ans-=2;
                continue;
            }
            cnt[i]--;
            if(i!=cnt.size()) cnt[i+1]--;
            ans-=2;
        }
    }
    cout << ans << endl;
}