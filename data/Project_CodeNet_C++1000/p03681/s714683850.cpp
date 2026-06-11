#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int main(){
	long long n,m;
	cin>>n>>m;
	long long inf=1000000007;

	if(abs(n-m)>=2){
		cout<<0<<endl;
		return 0;
	}

	long long ans=1;

	for(long long i=1;i<=n;i++){
		ans=(ans*i)%inf;
	}

	for(long long i=1;i<=m;i++){
		ans=(ans*i)%inf;
	}

	cout<<(n==m ? (ans*2)%inf : ans)<<endl;

	return 0;
}
