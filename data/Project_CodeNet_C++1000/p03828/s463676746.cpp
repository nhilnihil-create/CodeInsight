#include<bits/stdc++.h>
using namespace std;
int arr[1005];
int moder = 1000000007;
int main(){
	int n;
	cin>>n;
	for(int i=1; i<=n; i++){
		int curr = i;
		for(int j=2; j*j<=curr; j++){
			while(curr%j==0){
				curr/=j;
				arr[j]++;
			}
		}
		arr[curr]++;
	}
	long long ret = 1;
	for(int i=2; i<=n; i++){
		ret*=(arr[i]+1);
		ret%=moder;
	}
	cout<<ret;
}