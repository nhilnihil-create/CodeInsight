#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int main(){
	int n; cin>>n;
	int a[n]; long sum=0,b[n];
	rep(i,n){
		cin>>a[i];
		sum+=a[i];
		b[i]=sum;
	}
	long ans=abs(sum-2*b[0]);
	rep(i,n-1){
		if(abs(sum-2*b[i])<ans) ans=abs(sum-2*b[i]);
	}
	cout<<ans<<endl;
	return 0;
}
