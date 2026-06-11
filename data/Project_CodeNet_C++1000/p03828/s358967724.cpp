#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll INF=1e9+7;

int n;
int p[1001];

int c(int i){
	int a=0,b=n;
	while (b>=i){
		b/=i;
		a+=b;
	}
	return a;
}

int main(){
	cin>>n;
	for (int i=2;i<=1000;i++)
		if (!p[i])
			for (int j=i+i;j<=1000;j+=i)
				p[j]=1;
	ll ans=1;
	for (int i=2;i<=n;i++)
		if (!p[i]){
			ans*=c(i)+1;
			ans%=INF;
		}
	cout<<ans<<endl;
	return 0;
}