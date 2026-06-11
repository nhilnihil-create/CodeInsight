#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
using ll = long long;

int main() {
    ll n,X=0,Y=0;
    cin >> n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++){
         cin >> a[i];
         Y+=a[i];
    }
    X=a[0],Y-=a[0];
    ll ans=abs(X-Y);
    for(ll i=1;i<n-1;i++){
        X+=a[i];
        Y-=a[i];
        ans=min(abs(X-Y),ans);
    }
    cout << ans << endl;
	return 0;
}