#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n;
    cin >> n;
    string s1,s2;
    cin >> s1 >> s2;
    ll ans=1;
    vector<ll>data;//0:縦,1:横
    for(ll i=0;i<n;i++){
        if(s1[i]!=s2[i]){
            data.push_back(1);
            i++;
        }else{
            data.push_back(0);
        }
    }
    if(data[0]==0) ans*=3;
    else ans*=6;
    for(ll i=1;i<data.size();i++){
        if(data[i]==0&&data[i-1]==0){
            ans*=2;
            ans%=MOD;
        }else if(data[i]==1&&data[i-1]==1){
            ans*=3;
            ans%=MOD;
        }else if(data[i]==1&&data[i-1]==0){
            ans*=2;
            ans%=MOD;
        }
    }
    cout << ans << endl;
}