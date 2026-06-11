#include <iostream>
using namespace std;
typedef long long ll;
ll n, k, d, s, M=1e9+7;
string a, b;
 
int main() {
	cin>>n>>a>>b;
	a[k]==b[k] ? (d=1,s=3) : (d=2,s=6);
	k += d;
	while(k<n) {
		if(a[k]==b[k]) s*=3-d, d=1;
		else s*=d+1, d=2;
		k += d;
		s %= M;
	}
	cout<<s;
	return 0;
}
