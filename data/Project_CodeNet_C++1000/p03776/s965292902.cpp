#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define mp make_pair
#define inf 1000000007
#define int long long
using namespace std;
map<int,int> mope;
ll comb(int n,int k){
	ll res = 1;
	for(int i=1;i<=k;i++){
		res *= n-i+1;
		res /= i;
	}
	return res;
}
signed main(){
	int n,a,b;
	cin>>n>>a>>b;
	vector<ll> v;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		v.pb(x);
		mope[x]++;
	}
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	if(v[0]==v[a-1]){
		int cnt = mope[v[0]];
		double ans = 1.0 * v[0];
		int ans2 = 0;
		for(int i=a;i<=min(mope[v[0]],b);i++){
			ans2 += comb(mope[v[0]],i);
		}
		cout<<setprecision(12)<<ans<<endl;
		cout<<ans2<<endl;
	}
	else{
		int cnt = mope[v[a-1]];
		double ans = 0.0;
		int fl=-1;
		for(int i=0;i<a;i++){
			ans += 1.0*v[i];
			if(v[i]!=v[a-1])fl=i;
		}
		ans /= 1.0 * a;
		int cnt2 = a-1-fl;
		int ans2 = comb(cnt,cnt2);
		cout<<setprecision(12)<<ans<<endl;
		cout<<ans2<<endl;
	}
	return 0;
}