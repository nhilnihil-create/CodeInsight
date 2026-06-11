#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define fi first
#define se second
const int N = 3e6+6;
const int mod = 1e9+7;
const int inf = 1e8;
ll ar[N];
void solve(){
    ll n,a,b;
    cin>>n>>a>>b;
    ll ans = 0;
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    for(int i=1;i<n;i++){
        ll trt = min((ar[i]-ar[i-1])*a,b);
        ans+=trt;
    }
    cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
//    cin>>t;
    while(t--)solve();
    return 0;
}
