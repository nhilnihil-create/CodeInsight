#include <bits/stdc++.h>
using namespace std;

long long N,K,tmp;

long long fpb(long long a, long long b){
	if(b==0){
		return a;
	}else{
		return fpb(b,a%b);
	}
}

int main(){
	cin>>N>>K;
	long long curr; bool pos=false;
	cin>>curr;
	if(K<=curr)pos=true;
	for(int i=1; i<N; i++){
		cin>>tmp;
		if(K<=tmp)pos=true;
		curr=fpb(curr,tmp);
	}
	if(fpb(curr,K)!=curr||!pos){
		cout<<"IMPOSSIBLE"<<'\n';
	}else{
		cout<<"POSSIBLE"<<'\n';
	}
}