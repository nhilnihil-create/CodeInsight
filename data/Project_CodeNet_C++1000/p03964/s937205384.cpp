#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
	ll n,a,b,res1,res2;
	cin>>n>>a>>b;
	res1=a,res2=b;
	for (int i=1;i<n;i++){
		cin>>a>>b;
		ll t1=res1/a;
		ll t2=res2/b;
		if (res1%a) t1++;
		if (res2%b) t2++;
		res1=a*max(t1,t2);
		res2=b*max(t1,t2);
	}
	cout<<res1+res2<<endl;
	return 0;
}