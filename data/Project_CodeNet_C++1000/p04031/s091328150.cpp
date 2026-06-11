#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
	int arr[n];
	float sum(0);
	for(int i=0;i<n;i++){
			cin>>arr[i];
			sum += arr[i];
		}
	int f = floor(sum / n);
	int c = ceil(sum / n);
	
	int ans1(0),ans2(0);
	for(int i=0;i<n;i++){
	 ans1 += pow(arr[i] - f,2);
	 ans2 += pow(arr[i]-c,2);
	}	
	
	int ans = min(ans1,ans2);
	cout<<ans;
	return 0;
	} 
