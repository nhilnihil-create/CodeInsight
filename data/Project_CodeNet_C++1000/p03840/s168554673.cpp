#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main(){
	ll a[7];
	for(int i=0; i<7; i++) cin >> a[i];
	ll ans=a[1];
	ll p=2*(a[0]/2+a[3]/2+a[4]/2);
	ll q=3+2*((a[0]-1)/2+(a[3]-1)/2+(a[4]-1)/2);
	if(a[0]>0 && a[3]>0 && a[4]>0) ans+=max({p, q});
	else ans+=p;
	cout << ans << endl;
	return 0;
}