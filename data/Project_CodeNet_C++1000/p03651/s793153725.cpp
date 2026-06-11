#include <bits/stdc++.h>
using namespace std;


int main()
{
	long long n,k,a,b,arr[100006];
	cin>>n>>k;
	long long g = 0;
	long long m = -1;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		g = __gcd(g,arr[i]);
		m = max(m,arr[i]);
	}
	if(k>m || (k%g!=0)){
		cout<<"IMPOSSIBLE";
	}
	else
		cout<<"POSSIBLE";
	return 0;
}