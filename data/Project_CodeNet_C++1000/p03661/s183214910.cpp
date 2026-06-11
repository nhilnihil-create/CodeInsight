#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> PII;
typedef long long ll;

int main(){
	int n,a[200000];
	cin>>n;

	ll total=0;
	for (int i = 0; i < n; ++i){
		cin>>a[i];
		total+=a[i];
	}


	ll sum=0,ans=1e+18;
	for (int i = 0; i < n-1; ++i){
		sum+=a[i];
		ans=min(ans,abs(sum-(total-sum)));
	}

	cout<<ans<<endl;
}