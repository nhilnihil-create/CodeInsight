#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define mp make_pair
#define inf 1000000007
using namespace std;
int dp[114514][18];
int dsafter(int pos, int day){
	if(day == 0){
		return pos;
	}
	else{
		int cnt = 0, cur = day;
		while( cur/2 > 0){
			cnt++;
			cur /= 2;
		}
		return dsafter( dp[pos][cnt], day-(1<<cnt) );
	}
}
int solve(int a,int b,int n){
	if(a>b)return solve(b,a,n);
	int lef = 0, rig = n;
	while(rig - lef > 1){
		int mid = (lef+rig)/2;
		int plac = dsafter(a,mid);
		//cout<<a<<" "<<mid<<" "<<plac<<endl;
		if( plac >= b){
			rig = mid;
		}
		else{
			lef = mid;
		}
	}
	return rig;
}
int main(){
	int n;
	cin>>n;
	vector<ll> x;
	set<ll> sx;
	map<int,int> mp;
	for(int i=0;i<n;i++){
		ll tx;
		cin>>tx;
		x.pb(tx);
		sx.insert(tx);
		mp[tx]=i;
	}
	x.pb(2000000009);
	mp[2000000009]=n;
	sx.insert(2000000009);
	int l,q;
	cin>>l>>q;
	for(int i=0;i<n;i++){
		set<ll>::iterator it = sx.upper_bound( x[i]+l );
		dp[i][0] = mp[*it];
		dp[i][0]--;
		//cout<<"dp"<<i<<0<<" "<<dp[i][0]<<endl;
	}
	for(int j=1;j<=17;j++){
		for(int i=0;i<n;i++){
			dp[i][j] = dp[ dp[i][j-1] ][j-1];
		}
	}
	vector<ll> ans;
	for(int i=0;i<q;i++){
		int a,b;
		cin>>a>>b;
		ans.pb(solve(a-1,b-1,n));
	}
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}