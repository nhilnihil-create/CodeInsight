#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    int n,m;
    cin >> n >> m;
    if(abs(n-m)>1){
        cout << 0 << endl;
        return 0;
    }
    ll ans=1;
    if(n==m){
        for(int i=0;i<n;i++){
            ans*=(n-i);
            ans%=MOD;
            ans*=(n-i);
            ans%=MOD;
        }
        ans*=2;
        ans%=MOD;
    }
    else{
        for(int i=0;i<n;i++){
            ans*=(n-i);
            ans%=MOD;
        }
        for(int i=0;i<m;i++){
            ans*=(m-i);
            ans%=MOD;
        }
    }
    cout << ans << endl;
}
