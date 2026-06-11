#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define mp make_pair
#define inf 1000000007
#define LINF 1000000000000000007LL
#define ll long long
using namespace std;
signed main(){
	int n;
	cin>>n;
	vector<int> a;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		a.pb(x);
	}
	int cur = 1;
	int ans = 0;
	for(int i=0;i<n;i++){
		if( cur == 1 ){
			ans += a[i]-1;
			cur++;
		}
		else if( a[i] > cur){
			ans += (a[i]-1)/cur;
		}
		else if( a[i] == cur){
			cur++;
		}
	}
	cout<<ans<<endl;
	return 0;
}