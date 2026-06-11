#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n;
    ll k;
    cin >> n >> k;
    vector<ll>d(10,0);
    for(ll i=1;i<10;i++){
        d[i]=i;
    }
    for(ll i=0;i<k;i++){
        ll x;
        cin >> x;
        d[x]=10;
    }
    sort(d.begin(),d.end());
    ll ans=0;
    ll copy=n;
    ll keta=0;
    while(copy>0){
        keta++;
        copy/=10;
    }
    copy=n;
    vector<ll>num(keta);
    for(ll i=0;i<keta;i++){
        num[keta-i-1]=copy%10;
        copy/=10;
    }
    bool judge=true;
    bool judge1=false;
    for(ll i=0;i<keta;i++){
        for(ll j=0;j<10;j++){
            if(d[j]==10){
                judge1=true;
                judge=false;
                break;
            }
            if(num[i]<d[j]||judge==false){
                break;
            }
            if(num[i]==d[j]&&judge){
                break;
            }
        }
    }
    for(ll i=0;i<keta;i++){
        if(judge1){
            if(d[0]!=0){
                ans+=d[0]*pow(10,keta);
                ans+=d[0]*pow(10,keta-1);
            }
            else {
                ans+=d[1]*pow(10,keta);
                ans+=d[0]*pow(10,keta-1);
            }
            judge1=false;
            continue;
        }
        for(ll j=0;j<10;j++){
            if(num[i]<d[j]||judge==false){
                ans+=d[j]*pow(10,keta-i-1);
                judge=false;
                break;
            }
            if(num[i]==d[j]&&judge){
                ans+=d[j]*pow(10,keta-i-1);
                break;
            }
        }
    }
    cout << ans << endl;
}