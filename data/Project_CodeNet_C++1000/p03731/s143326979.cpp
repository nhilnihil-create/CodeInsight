#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[200005],i;

signed main(){
	int n,t,sum=0;
	cin>>n>>t;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=2;i<=n;i++){
		if(a[i]>=a[i-1]+t)
			sum+=t;
		else
			sum+=a[i]-a[i-1]; 
	}
	cout<<sum+t<<endl;
	return 0;
}