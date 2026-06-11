#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n,m;
	cin>>n>>m;
	long long inf=1e9+7;

	if(abs(n-m)>1){
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

	cout<<(n==m ? (ans*2)%inf : ans)<<endl;//(条件)?真の処理:偽の処理; //:ansのansってどのans?
	return 0;
}
