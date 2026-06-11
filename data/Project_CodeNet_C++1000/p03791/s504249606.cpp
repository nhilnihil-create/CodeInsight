#include <bits/stdc++.h>
#define MAX 1000001
#define INF 1000000000
#define M 1000000007
#define ll long long
#define zero(x) memset(x,0,sizeof(x))
using namespace std;

int main(){
	int n;
	cin >> n;
	int x[n];
	for (int i=0;i<n;i++) cin >> x[i];
	ll z,o;
	z = x[1]-2;
	o = 2;
	ll res = 1;
	ll prev = x[1];
	for (int i=2;i<n;i++){
		if (z+1<o){
			res = (res*o)%M;
			o--;
			z++;
		}
		z+=(x[i]-prev-1);
		o++;
		prev = x[i];
	}
	ll fac = 1;
	for (ll i=2;i<=o;i++){
		fac = (fac*i)%M;
	}
	res = (res*fac)%M;
	cout << res;
	return 0;
}