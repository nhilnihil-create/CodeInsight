#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define mp make_pair
#define inf 1000000007
#define LINF 1000000000000000007LL
#define ll long long
using namespace std;
signed main(){
	int h,w;
	cin>>w>>h;
	vector<pair<int,int> > edg;
	for(int i=0;i<w;i++){
		int x;
		cin>>x;
		edg.pb( mp( x, 0 ) );
	}
	for(int i=0;i<h;i++){
		int x;
		cin>>x;
		edg.pb( mp( x, 1) );
	}
	int hcnt = 0, wcnt = 0;
	sort( edg.begin(), edg.end() );
	int cur = 0, ans = 0;
	int lmt = (w+1)*(h+1) - 1;
	for(int i=0; i<edg.size();i++){
		int cost = edg[i].first;
		int tpe = edg[i].second;
		int num;
		if( tpe == 0 ){
			num = h+1-hcnt;
			wcnt++;
			num = min( num, lmt - cur );
			cur += num;
			ans += cost * num;
		}
		else{
			num = w+1 - wcnt;
			hcnt++;
			num = min( num, lmt - cur );
			cur += num;
			ans += cost * num;
		}
		if(lmt == cur)break;
	}
	cout<<ans<<endl;
	return 0;
}