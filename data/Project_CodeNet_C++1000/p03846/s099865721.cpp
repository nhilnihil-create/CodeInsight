#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	map<int,int> check;

	for(int i=0;i<n;i++){
		int hoge;
		cin>>hoge;
		if(check.count(hoge)) check.at(hoge)++;
		else check[hoge]=1;
	}

	bool ok=true;
	int a=n%2==0 ? 1 : 0;

	for(int i=0+a;i<n;i+=2){
		if(!check.count(i)){
			ok=false;
			break;
		}

		if(i==0){
			if(check.at(i)!=1) ok=false;
		}else{
			if(check.at(i)!=2) ok=false;
		}
	}

	long long ans=0;

	if(ok){
		ans++;
		for(int i=0;i<floor((double)n/2);i++){
			ans*=2;
			ans%=1000000007;
		}
	}

	cout<<ans<<endl;

	return 0;
}
