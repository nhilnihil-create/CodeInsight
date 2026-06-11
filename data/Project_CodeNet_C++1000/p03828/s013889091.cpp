#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int prime[n+1];
	int pr[n+1],x=0;
	int pri[n+1];
	for(int i=1;i<=n;i++){
		prime[i]=0;
		pri[i]=0;
	}
	for(int i=2;i<=n;i++){
		if(!prime[i]){
			x++;
			pr[x]=i;
			for(int j=i+i;j<=n;j+=i){
				prime[j]=1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		int p=i;
		for(int j=1;j<=x;j++){
			while(p%pr[j]==0){
				p/=pr[j];
				pri[pr[j]]++;
			}
		}
	}
	long long p=1;
	for(int i=1;i<=n;i++){
		p*=(pri[i]+1);
		p%=1000000007;
	}
	cout<<p<<endl;
}