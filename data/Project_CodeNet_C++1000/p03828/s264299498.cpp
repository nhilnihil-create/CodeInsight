#include<bits/stdc++.h>
using namespace std;
long long n,pri[1111],ans=1;
long long ced(long long i){
	long long a=0,q=n;
	while(q>=i){
		q/=i;
		a+=q;
	}
	return a;
}
int main(){
	cin>>n;
	pri[0]=1;pri[1]=1;
	for(long long i=2;i<=n;i++){
		if(!pri[i]){
			for(long long j=i+i;j<=n;j+=i)pri[j]=1;
		}
	}
	for(long long i=2;i<=n;i++){
		if(!pri[i]){
			ans*=ced(i)+1;
			while(ans>1e9+7)ans=ans-(1e9+7);
		}
	}
	cout<<ans;
	return 0;
}