#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define mp make_pair
#define inf 1000000007
#define LINF 1000000000000000007LL
#define ll long long
using namespace std;
signed main(){
	int n,k;
	cin>>n>>k;
	vector<int> a,b;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		a.pb(x);b.pb(y);
	}
	if( k == 0 ){
		int tmp = 0;
		for(int i=0;i<n;i++){
			if( a[i] == 0 ) tmp += b[i];
		}
		cout<<tmp<<endl;
		return 0;
	}
	int ans = 0;
	for(int i=0;i<n;i++){
		if( (k|a[i]) == k)ans+=b[i];
		//cout<<k<<" "<<ans<<endl;
	}
	for(int i=29;i>=0;i--){
		int tmp = 0;
		int md = 1<<(i+1);
		int hf = 1<<i;
		int cur = k;
		if( cur % md >= hf ){
			cur = cur/hf * hf;
			cur--;
			for(int j=0;j<n;j++){
				if( (cur|a[j]) == cur)tmp+=b[j];
			}
			//cout<<cur<<" "<<tmp<<endl;
		}
		if(tmp>ans)ans=tmp;
	}
	cout<<ans<<endl;
	return 0;
}