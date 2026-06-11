#include <iostream>
#include<vector>
using namespace std;

int main() {
	int n;cin>>n;
	vector<long long> s(n),a(n);
	long long sum=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	s[0]=a[0];
	for(int i=1;i<n;i++){
		s[i]=s[i-1]+a[i];
	}
	long long ans=s[0]-(sum-s[0]);
	if(ans<0){
		ans*=-1;
	}
	for(int i=1;i<n-1;i++){
		long long temp=s[i]-(sum-s[i]);
		if(temp<0)temp*=-1;
		if(ans>temp)ans=temp;
	}
	cout<<ans<<endl;

	return 0;
}
