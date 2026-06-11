#include<bits/stdc++.h>
using namespace std;
int main(){
	int a=0,n,x[1005],y[1005];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i];
		a=a+(y[i]-x[i]+1);
	}
	cout<<a<<endl;
	return 0;
}
