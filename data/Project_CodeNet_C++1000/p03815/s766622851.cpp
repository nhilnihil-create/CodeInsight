#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define fi first
#define se second
const int N = 3e3+6;
const int mod = 1e9+7;
const int inf = 1e8;
void solve(){
    ll x;
    cin>>x;
    ll ans = x/11;
    ans*=2;
    if(x%11>0)ans++;
    if(x%11>6)ans++;
    cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
//    cin>>t;
    while(t--)solve();
    return 0;
}
