#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()	
{
	int n,k;
	cin>>n>>k;
	int mx = -1;
	int a[n];

	for(int i=0;i<n;i++){ 
		cin>>a[i];
		mx = max(mx,a[i]);
	}

	int gcd = a[0];
	
	for(int i=1;i<n;i++)
		gcd = __gcd(a[i],gcd);


	if(mx<k||(k%gcd!=0)){
		puts("IMPOSSIBLE");
	}

	else{
		puts("POSSIBLE");
	}
}