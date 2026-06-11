#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	long long a,b;
	cin>>a>>b;
	vector<int>arr(n);
	for(int i=0; i<n; i++) cin>>arr[i];
	long long ret = 0;
	for(int i=0; i<n-1; i++){
		long long d = arr[i+1]-arr[i];
		long long walk = d*a;
		ret+=min(walk,b);
	}
	cout<<ret;
}