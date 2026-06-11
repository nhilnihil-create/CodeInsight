#include <bits/stdc++.h>
typedef long long int ll;
using namespace std; 
ll N = pow(10,10);
int main(){
	ios_base::sync_with_stdio(false);  
	cin.tie(NULL);
	int n;cin>>n;
	ll arr[2*n];
	for(int i=0;i<2*n;i++){
		ll l;cin>>l;
		arr[i] = l;
	}
	sort(arr,arr+2*n);
	ll sum=0;
	for(int i=0;i<2*n;i+=2){
		sum += arr[i];
	}
	cout<<sum<<endl;
}