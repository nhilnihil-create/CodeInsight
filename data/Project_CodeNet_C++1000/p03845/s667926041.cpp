#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n,temp=0;
	cin>>n;
	long arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
		temp+=arr[i];
	}
	long cases;
	cin>>cases;
	while(cases--){
		long a,b;
		cin>>a>>b;
		long sum = temp - arr[a-1] + b;
		cout<<sum<<endl;
	}
	
	return 0;
}