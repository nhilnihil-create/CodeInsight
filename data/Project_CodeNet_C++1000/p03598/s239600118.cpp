#include <iostream>

using namespace std;

int main(){

	int n,k;
	cin>>n>>k;
	int a[n];
	long int ans=0;
	for(int i=0;i<n;i++){
	
		cin>>a[i];
		if(a[i]<=abs(k-a[i])){
			
			ans+=2*a[i];
		}
		else{
		
			ans+=2*abs(k-a[i]);
		}
	}
	cout<<ans<<'\n';
	return 0;
}
