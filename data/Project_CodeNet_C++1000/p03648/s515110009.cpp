#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
 
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	lld k;cin>>k;
	int n = ceil(k/10000000000000000.);
	if(n<2) n=2;
	cout<<n<<'\n';
	for(int i=0;i<n-1;i++){
		lld kn = k/n;
		if(i<k%n) kn++;
		cout<<n*kn-(k-kn)+n-2<<' ';
	}
	lld kn = k/n;
	cout<<n*kn-(k-kn)+n-1<<'\n';
	return 0;
}