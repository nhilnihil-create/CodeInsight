#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,i,j,sum,ans=10000000;
	cin>>n;
	int a[n+1];
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=-101;i<=101;i++){
		sum=0;
		for(j=1;j<=n;j++)
			sum+=(a[j]-i)*(a[j]-i);
		ans=min(sum,ans);	
	}
	cout<<ans<<endl;
	return 0;
}