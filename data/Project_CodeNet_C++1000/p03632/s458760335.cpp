#include <bits/stdc++.h>
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define mod 1000000007
#define pb push_back
#define F first
#define S second
using namespace std;

int main(void) {
	boost
	;
	ll a;
	cin >> a;
	ll b;
	cin >> b;
	ll c;
	cin >> c;
	ll d;
	cin >> d;
	ll ans=min(b,d)-max(a,c);
	if(ans<0){
		ans=0;
	}
	cout<<ans;
	return 0;
}
