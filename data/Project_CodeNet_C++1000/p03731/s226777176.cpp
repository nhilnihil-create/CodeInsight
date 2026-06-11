#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int main(){
	int n,t;
	cin>>n>>t;
	long long ans=0;
	int now=0,pre=0;
	cin>>now;

	for(int i=0;i<n-1;i++){
		pre=now;
		cin>>now;

		ans+=min(t,now-pre);
	}

	cout<<ans+t<<endl;

	return 0;
}
