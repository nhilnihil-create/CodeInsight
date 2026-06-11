#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

int main(){
    vector<ll> num(4);
    for(int i = 0; i < 4; i++) cin >> num[i];
    ll n;
    cin >> n;
    ll ans = (n*4)*num[0];
    ans = min((n*2)*num[1],ans);
    ans = min(ans,n*num[2]);
    if(n%2 == 1){
        ans = min(ans,(n/2)*num[3]+min(num[0]*4,min(num[1]*2,num[2])));
    }else ans = min(ans,(n/2)*num[3]);
    cout << ans << endl;
    return 0;
}