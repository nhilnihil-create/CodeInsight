#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
const ll MOD=1e9+7;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    string s,t;
    cin >> s >> t;
    vector<bool> dom;
    for(int i = 0; i < n; i++) {
        if(s[i]==t[i]) dom.emplace_back(true);
        else{
            dom.emplace_back(false);
            i++;
        }
    }
    ll ans;
    if(dom[0]==1) ans=3;
    else ans=6;
    for(int i = 1; i < dom.size(); i++) {
        if(dom[i-1]==true && dom[i]==true)       ans=(ans*2)%MOD;
        else if(dom[i-1]==true && dom[i]==false) ans=(ans*2)%MOD;
        else if(dom[i-1]==false && dom[i]==true) ans%=MOD;
        else ans=(ans*3)%MOD;
    }
    cout << ans << "\n";

    return 0;
}