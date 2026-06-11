#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,a[200000];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	long long sum1=a[0],sum2=accumulate(a+1,a+n,0ll),ans=abs(sum2-sum1);
	for(int i=1;i<n-1;i++){
		sum1+=a[i];
		sum2-=a[i];
		ans=min(ans,abs(sum2-sum1));
	}
	cout<<ans<<endl;
}
