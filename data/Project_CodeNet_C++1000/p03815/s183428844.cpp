#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    ll x,ans;
    cin>>x;
    ans=(x/11)*2;
    if (x%11>0) {
        if (x%11>6) ans+=2;
        else ans++;
    }
    cout<<ans<<endl;
}
