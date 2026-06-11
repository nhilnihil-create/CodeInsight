#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
ull gcd(ull a,ull b){
	return b?gcd(b,a%b):a;
}
ull lcm(ull a,ull b){ 
	ull x=a/gcd(a,b);
	return x*b; 
}
int main()
{
	ull n;cin>>n;
	ull a;cin>>a;
	ull ans=a;
	for(int i=1;i<n;i++){
		cin>>a;
		ans=lcm(ans,a);
	}
	cout<<ans;
	return 0;
} 