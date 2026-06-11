#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n,m;
    cin >> n >> m;
    vector<ll>x(m),y(m);
    for(ll i=0;i<m;i++){
        cin >> x[i] >> y[i];
        x[i]--;
        y[i]--;
    }
    vector<ll>num(n,1);
    vector<bool>data(n,false);
    data[0]=true;
    for(ll i=0;i<m;i++){
        if(data[x[i]]){
            data[y[i]]=true;
        }
        num[x[i]]--;
        num[y[i]]++;
        if(num[x[i]]==0){
            data[x[i]]=false;
        }
    }
    ll ans=0;
    for(ll i=0;i<n;i++){
        if(data[i]) ans++;
    }
    cout << ans << endl;
}