#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,x;
	cin>>n>>x;
	vector<int>arr(n);
	long long ret = 0;
	for(int i=0; i<n; i++) cin>>arr[i];
	arr.push_back(0);
	for(int i=0; i<n; i++){
		if(arr[i]+arr[i+1]>x){
			int remove = arr[i]+arr[i+1]-x;
			ret+=remove;
			arr[i+1]-=min(arr[i+1],remove);
		}
	}
	cout<<ret;
}