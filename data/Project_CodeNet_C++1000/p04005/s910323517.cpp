#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    ll a[3];rep(i,3)cin>>a[i];
    rep(i,3)if(a[i]%2==0){
        cout<<0<<endl;
        return 0;
    }
    sort(a,a+3);
    ll m1 = a[2]/2;
    ll m2 = a[2]-m1;
    ll ans = (m2-m1)*a[0]*a[1];
    cout<<ans<<endl;
	return 0;
}