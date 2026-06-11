#include<iostream>
#include<algorithm>
using namespace std;
int a[110];
int main(){
	int n;
	cin>>n;
	n*=2;
	for(register int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+n+1);
	int ans=0;
	for(register int i=1;i<=n;i+=2)
	ans+=a[i];
	cout<<ans<<endl;
	return 0;
}