#include <bits/stdc++.h>
using namespace std;

int N,tmp,even=0,odd=0;

int main(){
	cin>>N;
	for(int i=0; i<N; i++){
		cin>>tmp;
		(tmp%2==0 ? even++ : odd++);
	}
	if(odd%2==1){
		if(odd==1&&even==0){
			cout<<"YES"<<'\n';
		}else{
			cout<<"NO"<<'\n';
		}
	}else{
		cout<<"YES"<<'\n';
	}
}