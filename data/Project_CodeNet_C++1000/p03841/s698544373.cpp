#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define int long long
#define mp make_pair
#define inf 1000000007
using namespace std;
ll ans[1000009],plc[509];
int addnum(int st, int num, int ct,int mv){
	int cnt = 0;
	int cid = st;
	while( cnt < ct && cid>=0){
		if(ans[cid]==0){
			ans[cid] = num;
			cnt++;
		}
		cid += mv;
	}
	return cid;
}

signed main(){
	int n;
	cin>>n;
	vector< pair<int,int> > v,r;
	vector<int> chec;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		v.pb(mp(x,i));
		r.pb(mp(x,i));
		ans[x]=i;
		chec.pb(x);
	}
	sort(v.begin(),v.end());
	sort(r.begin(),r.end());
	reverse(r.begin(),r.end());
	ll cur = 1;
	for(int i=0;i<n;i++){
		cur = addnum(cur,v[i].second, v[i].second-1, 1);
	}
	cur = n*n;
	for(int i=0;i<n;i++){
		cur = addnum(cur,r[i].second,n-r[i].second,-1);
	}
	map<int,int> mope;
	for(int i=1;i<=n*n;i++){
		mope[ ans[i] ] ++ ;
		if(mope[ ans[i] ] == ans[i]){
			plc[ ans[i] ] = i;
			//cout<<ans[i]<<" "<<i<<endl;
		}
	}
	for(int i=1;i<=n;i++){
		if( plc[i] != chec[i-1]){
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
	for(int i=1;i<=n*n;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}