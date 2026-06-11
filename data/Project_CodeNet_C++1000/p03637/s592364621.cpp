#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int arr[n];
	int moder[4]={0};
	for(int i=0; i<n; i++){
		cin>>arr[i];
		arr[i]%=4;
		moder[arr[i]]++;
	}
	int pos = moder[0];
	int impos = moder[1]+moder[3]+(moder[2]?1:0);
	if(pos>=impos-1) cout<<"Yes";
	else cout<<"No";
}