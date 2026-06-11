#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);  
	cin.tie(NULL);
	int k,n;cin>>k>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		int a;cin>>a;
		arr[i] = a;
	}
	sort(arr,arr+n);
	int ans=0;
	if(n==1){
		ans = arr[0]-1;	
	}
	else{
		int sum=0;
		for(int i=0;i<n-1;i++){
			sum += arr[i];
		}
		sum += arr[n-2];
		ans = max(0,arr[n-1]-arr[n-2]-(sum+1-2*arr[n-2]));
	}
	cout<<ans<<endl;
}