#include <bits/stdc++.h>
 
using namespace std;

#define esp 1e-9

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long long int n;
	cin>>n;
	int f=0;
	for(long long int i=2;i*i<=n;i++){
		if(n%i==0){
			f=1;
			break;
		}
	}
	if(f==0){
		long long int xxx=log10(n)+1+esp;
		cout<<xxx;
	}
	else{
		for(long long int i=sqrt(n)+1;i>=1;i--){
			if(n%i==0){
				long long int xx=n/i;
				long long int a=log10(i)+1+esp;
				long long int b=log10(xx)+1+esp;
				cout<<max(a,b);
				break;
			}
		}
	}
	return 0;
}