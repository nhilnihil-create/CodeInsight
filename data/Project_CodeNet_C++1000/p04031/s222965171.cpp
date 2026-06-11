#include <bits/stdc++.h>
using namespace std;
int arr[101];
int main() {
	int n;
	cin>>n;
	
	for(int i=0; i<n; i++) cin>>arr[i];
	
	int ans=10000000;
	for(int x=-100; x<=100; x++){
		int t=0;
		for(int i=0; i<n; i++){
			
			t += (x-arr[i])*(x-arr[i]);
		
		}
		
		ans= min(ans, t); 
	}
	
	cout<<ans;
	return 0;
}
