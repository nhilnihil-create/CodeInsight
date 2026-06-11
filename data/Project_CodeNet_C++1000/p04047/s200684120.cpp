#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	int n;
	long long ans=0;
	cin>>n;
	for(int i=1;i<=2*n;i++)
		cin>>a[i];
	sort(a+1,a+2*n+1);
	for(int i=1;i<=n;i++){
		ans+=a[i*2-1];
	}
	cout<<ans;
	return 0;
}