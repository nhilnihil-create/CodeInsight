#include <iostream>
using namespace std;
int main()
{
	long long n,k,x,y,res;
	cin>>n>>k>>x>>y;
	if(k<n) res=x*k + (n-k)*y;
	else res=x*n;
	cout<<res<<endl;
}