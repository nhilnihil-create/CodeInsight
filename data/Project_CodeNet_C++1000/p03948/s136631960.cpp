#include <iostream>
#include<vector>
using namespace std;

int main() {
	int n,t;cin>>n>>t;
	vector<int> a(n),min(n),max(n);

	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	min[0]=a[0];
	for(int i=1;i<n;i++){
		if(a[i]<min[i-1]){
			min[i]=a[i];
		}else{
			min[i]=min[i-1];
		}
	}
	max[n-1]=a[n-1];
	for(int i=n-2;i>=0;i--){
		if(a[i]>max[i+1]){
			max[i]=a[i];
		}else{
			max[i]=max[i+1];
		}
	}
	int maxd=0;
	for(int i=0;i<n;i++){
		if(max[i]-a[i]>maxd){
			maxd=max[i]-min[i];
		}
	}
	int ans=0;
	for(int i=0;i<n;i++){
		if(max[i]-a[i]==maxd){
			ans++;
		}
	}
//	for(int i=0;i<n;i++){
//		cout<<max[i]<<' ';
//	}
//	cout<<endl;
	cout<<ans<<endl;
	return 0;
}