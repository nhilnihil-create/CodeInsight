#include <bits/stdc++.h>
using namespace std;


int main()
{
	long long n,a,b,x,y;
	cin>>n;
	cin>>a>>b;
	if(n==1){
		cout<<(a==b);
		return 0;
	}
	if(a>b){
		cout<<0;
		return 0;
	}
	n-=2;
	x = b-a;
	x*=n;
	x+=1;
	cout<<x;
	return 0;
}