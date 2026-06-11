#include <bits/stdc++.h>
using namespace std;

long long N,arr[200010];

int main(){
	cin>>N;
	long long increase=0,total=1;
	cin>>arr[0];
	for(int i=1; i<N; i++){
		cin>>arr[i];
		if(increase==1){
			if(arr[i]<arr[i-1]){
				total++;
				increase=0;
			}
		}else if(increase==2){
			if(arr[i]>arr[i-1]){
				total++;
				increase=0;
			}
		}else if(increase==0){
			if(arr[i]<arr[i-1]){
				increase=2;
			}else if(arr[i]>arr[i-1]){
				increase=1;
			}
		}
	}
	cout<<total<<'\n';
}