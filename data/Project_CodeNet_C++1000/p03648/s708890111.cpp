#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 50;
ll k, a[60];

int main() {
	cin>>k;
	
	cout<<N<<endl;
	ll t = k / N;
	ll m = k % N;
	for(int i=0;i<N;i++)a[i] = i + t;

	for(int i=0;i<m;i++)a[i] += (N - m + 1);
	for(int i=m;i<N;i++)a[i] -= m;
	
	for(int i=0;i<N;i++)
		printf("%lld%c",a[i],i==49?'\n':' ');
		
	return 0;
}