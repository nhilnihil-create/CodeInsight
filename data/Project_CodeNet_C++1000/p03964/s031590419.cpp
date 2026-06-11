#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n;
	cin>>n;
	ll t, a; cin>>t>>a;
	for(int i = 1; i < n; i++){
		ll nt, na;
		cin>>nt>>na;
		ll k = max((t + nt - 1)/nt, (a + na - 1)/na);
		t = k*nt;
		a = k*na;
	}
	cout<<t + a<<endl;


	return 0;
}