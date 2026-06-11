#include <bits/stdc++.h>

using namespace std;

int main() {
	int N,K,X,Y,ans=0;

	cin>>N>>K>>X>>Y;

	for(int i=1;i<=N;i++) {
		if(i<=K) {
			ans+=X;
		} else {
			ans+=Y;
		} 
	}
	cout<<ans;

	return 0;
}