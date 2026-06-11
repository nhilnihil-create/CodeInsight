#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	int N,T; cin>>N>>T;
	int ans=0;
	int tmp1,tmp2; cin>>tmp1;
	for(int i=0;i<N-1;i++){
		cin>>tmp2;
		ans+=min(tmp2-tmp1,T);
		tmp1=tmp2;
	}
	ans+=T;
	cout<<ans<<endl;
}