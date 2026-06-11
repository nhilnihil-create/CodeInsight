#include <bits/stdc++.h>
#define mm(i,v) memset(i,v,sizeof i);
using namespace std;
typedef long long ll;
ll  N,A,B;
ll  x,now,pre;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>N>>A>>B;
	cin>>pre;
	ll ans=0;
	for(int i=2;i<=N;i++){
		cin>>x;
		now=(x-pre)*A;
		ans+=min(now,B);
		pre=x;
	}
	cout<<ans<<"\n";
	return 0;
}
