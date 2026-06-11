#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

int main(){
    ll a,b,x;
    cin>>a>>b>>x;
    ll ans=b/x;
    if(a==0) ans++;
    if(a!=0) ans-=(a-1)/x;

    cout<<ans<<endl;
}