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

	ll x; cin>>x;
	ll ret = 2*(x/11);
	x %= 11;
	if(x > 0)ret++;
	if(x > 6)ret++;
	cout<<ret<<endl;

	return 0;
}