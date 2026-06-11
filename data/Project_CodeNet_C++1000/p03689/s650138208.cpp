#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000



int main(){
	
	long long H,W,h,w;
	cin>>H>>W>>h>>w;
	
	vector<vector<long long>> ans(H,vector<long long>(W,0));
	
	long long m = -1000000000;
	
	for(long long i=0;i<H;i+=h){
		for(long long j=0;j<W;j+=w){
			ans[i][j] = (-m)-1;
		}
	}
	
	for(long long i=h-1;i<H;i+=h){
		for(long long j=w-1;j<W;j+=w){
			ans[i][j] = m;
		}
	}
	
	
	
	long long sum = 0;
	for(long long i=0;i<H;i++){
		for(long long j=0;j<W;j++){
			sum += ans[i][j];
		}
	}
	
	if(sum<=0){
		cout<<"No"<<endl;
		return 0;
	}
	else{
		cout<<"Yes"<<endl;
	}
	
	for(long long i=0;i<H;i++){
		for(long long j=0;j<W;j++){
			if(j!=0)cout<<' ';
			cout<<ans[i][j];
		}
		cout<<endl;
	}
	
	
	return 0;
}