#include <iostream>


using namespace std;

typedef long long int ll;


int main()
{
	ll i,o,t,j,l,s,z;
	cin>>i>>o>>t>>j>>l>>s>>z;

	ll ans = 0;
	ans += 2*o;

	ll ijl = min(min(i,j),l);
	ll res = 0;
	if(ijl>0){ // ijlを１個使う
		res += 6 + ((i-1)/2)*4 + ((j-1)/2)*4 + ((l-1)/2)*4;
	}

	ans += max(res,(i/2)*4 + (j/2)*4 + (l/2)*4);
	cout << ans/2 << endl;

	return 0;
}
