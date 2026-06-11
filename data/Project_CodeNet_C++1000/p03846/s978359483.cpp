#include<bits/stdc++.h>
using namespace std;

int main(){
	int counter[100005]={0};
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		int a;
		cin>>a;
		counter[a]++;
	}

	bool possible = true;
	if(n%2){
		if(counter[0]!=1){
			cout<<0;
			return 0;
		}
		for(int i=2; i<=n-1; i+=2){
			if(counter[i]!=2) possible = false;
		}
		if(!possible) cout<<0; 
	}
	else{
		for(int i=1; i<=n-1; i+=2){
			if(counter[i]!=2) possible = false;
		}
		if(!possible) cout<<0;
	}
	if(possible){
		int ret = 1;
		for(int i=0; i<n/2; i++){
			ret*=2;
			ret%=1000000007;
		}
		cout<<ret;
	}
}