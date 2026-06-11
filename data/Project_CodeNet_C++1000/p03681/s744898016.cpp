#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

ll factorial(int n) {
    ll x=1;
    for (int i=1; i<=n; i++) {
        x*=i;
        x%=MOD;
    }
    return x;
}

int main() {
    int n,m,maxi;
    cin>>n>>m;
    int diff=abs(n-m);
    ll ans,sum=n+m,temp;
    if (diff>=2) ans=0;
    else if(diff==1) {
        maxi=max(n,m);
        ans=factorial(maxi)*factorial(sum-maxi);
    } else {
        temp=factorial(n);
        ans=2*temp*temp;
    }
    ans%=MOD;
    cout<<ans<<endl;
}   
