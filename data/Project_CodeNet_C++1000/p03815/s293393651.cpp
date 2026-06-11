#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

 
int main() {
    ll x;
    cin>>x;
    ll ans=2*(x/11);
    ll ama=x%11;
    if(ama==0)cout<<ans<<endl;
    else if(ama<=6)cout<<ans+1<<endl;
    else cout<<ans+2<<endl;
}