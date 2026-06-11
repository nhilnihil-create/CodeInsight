#include <iostream>
#include <algorithm>
using namespace std;
int a[1000001],sum=0;
int main(){
	int i,j,k,n;
	cin>>n;
	n*=2;
	for(i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(i=1;i<=n;i+=2)sum+=a[i];
	cout<<sum<<endl;
	return 0;
}