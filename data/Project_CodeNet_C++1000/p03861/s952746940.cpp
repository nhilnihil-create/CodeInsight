#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll=long long;
using vi=vector<int>;
using vll=vector<ll>;
#define MOD 1e9+7

int main(){
    ll a,b,x;
    cin >> a >> b >> x;
    ll ans=b/x-(a/x+1)+1;
    if(a%x==0) ans++;
    cout << ans << endl;
}