#include<bits/stdc++.h>
using namespace std;
int n;
long long arr[100005];
long long temp[100005];
void copy_arr(){
	for(int i=1; i<=n; i++) temp[i] = arr[i];
	return;
}
long long solve(bool pos){
	long long ret = 0;
		for(int i=2; i<=n; i++){
			temp[i]+=temp[i-1];
			if((i%2)^(!pos)){ //양수 
				if(temp[i]>0) continue;
				else{
					ret+=1-temp[i];
					temp[i] = 1;
				}
			}
			else{ //음수  
				if(temp[i]<0) continue;
				else{
					ret+=temp[i]+1;
					temp[i] = -1;
				}
			}
		}
	return ret;
}
int main(){
	cin>>n;
	for(int i=1; i<=n; i++) cin>>arr[i];
	copy_arr();
	if(arr[1]>0){
		long long ret1 = solve(1);
		copy_arr();
		long long ret2 = arr[1]+1;
		temp[1] = -1;
		ret2+=solve(0);
		cout<<min(ret1,ret2);
	}
	else if(arr[1]==0){
		long long ret1 = 1;
		temp[1] = 1;
		ret1+=solve(1);
		copy_arr();
		long long ret2 = 1;
		temp[1] = -1;
		ret2+=solve(0);
		cout<<min(ret1,ret2);
	}
	else{
		long long ret1 = solve(0);
		copy_arr();
		long long ret2 = (1-arr[1]);
		temp[1] = 1;
		ret2+=solve(1);
		cout<<min(ret1,ret2);
	}
}