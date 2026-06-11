#include <iostream>
#include<vector>
using namespace std;

int main() {
	int n,m;cin>>n>>m;
	vector<long long> x(n),y(m);
	for(int i=0;i<n;i++){
		cin>>x[i];
	}
	for(int i=0;i<m;i++){
		cin>>y[i];
	}
	long long def=1;
	for(int i=0;i<9;i++){
		def*=10;
	}
	def+=7;
	int interval=n-1;
	vector<long long> mul(interval);
	long long temp=interval;
	mul[0]=temp;
	for(int i=1;i<(interval+1)/2;i++){
		temp+=interval-2*i;
		mul[i]=temp;
	}
	for(int i=interval-1;i>=interval/2;i--){
		mul[i]=mul[interval-i-1];
	}
	long long xsum=0;
	long long ysum=0;
	for(int i=0;i<interval;i++){
		xsum+=mul[i]*(x[i+1]-x[i]);
		if(xsum>def)xsum%=def;
	}
	interval=m-1;
	temp=interval;
	mul=vector<long long>(interval);
	mul[0]=temp;
	for(int i=1;i<(interval+1)/2;i++){
		temp+=interval-2*i;
		mul[i]=temp;
	}
	for(int i=interval-1;i>=interval/2;i--){
		mul[i]=mul[interval-i-1];
	}
	for(int i=0;i<interval;i++){
		ysum+=mul[i]*(y[i+1]-y[i]);
		if(ysum>def)ysum%=def;
	}
	long long ans=xsum*ysum;
	if(ans>def)ans%=def;
	cout<<ans<<endl;
	return 0;
}