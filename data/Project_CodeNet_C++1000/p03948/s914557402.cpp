#include<bits/stdc++.h>
using namespace std;
int n,t,a[100010],ans,num,p[100010];
int main(){
	cin>>n>>t;
	for (int i=0;i<n;i++) cin>>a[i];
	p[n-1]=a[n-1];
	for (int i=n-2;i>=0;i--){
		p[i]=p[i+1];
		if (p[i]<a[i]) p[i]=a[i];
	}
	for (int i=0;i<n;i++) num=max(num,p[i]-a[i]);
	for (int i=0;i<n;i++) if (p[i]-a[i]==num) ans++;
	cout<<ans<<endl;
	return 0;
}