#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

ll gcd(ll a, ll b) { //最大公約数
    if (b == 0) return a;
    else return gcd(b,a%b);
}

ll lcm(ll a, ll b) { //最小公倍数
    return a*(b/gcd(a,b));
}

int main() {
    int n;
    cin>>n;
    ll temp,ans=1LL;
    rep(i,n) {
        cin>>temp;
        ans=lcm(ans,temp);
    }
    cout<<ans<<endl;
}
