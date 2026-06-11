#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n;
    cin >> n;
    vector<ll>s(n);
    for(ll i=0;i<n;i++){
        cin >> s[i];
    }
    sort(s.begin(),s.end());
    ll ans=0;
    for(ll i=0;i<n;i++){
        ans+=s[i];
    }
    if(ans%10!=0){
        cout << ans << endl;
        return 0;
    }
    ll del=0;
    for(ll i=0;i<n;i++){
        if(s[i]%10!=0){
            del=s[i];
            break;
        }
    }
    ans-=del;
    if(del==0) ans=0;
    cout << ans << endl;
}