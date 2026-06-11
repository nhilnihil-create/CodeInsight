#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	long long int n;
	cin>>n;
	long long int x;
	cin>>x;
	long long int arr[n];
	for(long long int j=0;j<n;j++){
		cin>>arr[j];
		//cout<<arr[j]<<endl;
	}
	long long int eat= 0;
	long long int d=0;
	for(long long int i=0;i<n-1;i++){
		if(arr[i]+arr[i+1]>x){
			eat+=arr[i]+arr[i+1]-x;
			arr[i+1] =max(d,x-arr[i]);
		}
	}
	cout<<eat<<endl;
}