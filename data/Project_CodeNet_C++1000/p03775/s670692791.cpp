#include<bits/stdc++.h>
using namespace std;
int digits(long long n){
	int ret = 0;
	while(n){
		ret++;
		n/=10;
	}
	return ret;
}
int main(){
	long long n;
	cin>>n;
	long long maxfactor = 0;
	for(long long i=1; i*i<=n; i++){
		if(n%i==0) maxfactor = max(maxfactor,i);
	}
	cout<<digits(n/maxfactor);
}