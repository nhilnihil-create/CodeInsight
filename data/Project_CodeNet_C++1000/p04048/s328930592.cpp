#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	long long n,x; cin>>n>>x;
	long long ans = n;
	long long a,b, c;
	a = n - x; b = x; c = a / b;
	while(a%b != 0){
		ans += b * c * 2;
		long long tmp = a;
		a = b; 
		b = tmp % a;
		c = a / b;
	}
	ans += b * (c * 2-1);
	cout<<ans<<endl;
	return 0;
}

