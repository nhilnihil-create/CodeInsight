#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);

	int arr[3];
	for(int i=0;i<3;i++)
		cin>>arr[i];
		
	sort(arr,arr+3);
	if(arr[0]+arr[1] == arr[2]){
		cout<<"Yes";
	}else{
		cout<<"No";
	}
	
}

