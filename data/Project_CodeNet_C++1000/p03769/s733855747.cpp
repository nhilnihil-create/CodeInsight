#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000000

int main(){
	
	long long N;
	cin>>N;
	
	vector<int> pre,suf;
	
	for(int i=0;true;i++){
		if(N>=(1LL<<i)){
			N-=(1LL<<i);
			pre.push_back(i+1);
			suf.push_back(i+1);
		}
		else break;
	}
	//cout<<N<<endl;
	for(int i=50;i>=0;i--){
		if((1LL<<i)&N){
			pre.push_back(pre.back()+1);
			suf.insert(suf.begin()+i,pre.back());
		}
	}
	
	cout<<pre.size()*2<<endl;
	
	for(int i=0;i<pre.size();i++){
		if(i!=0)cout<<' ';
		cout<<pre[i];
	}
	
	for(int i=0;i<pre.size();i++){
		cout<<' ';
		cout<<suf[i];
	}
	cout<<endl;
	
	return 0;
}