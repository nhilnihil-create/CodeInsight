#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int h,w,n;
	cin >> h >> w >> n;
	
	set<pii> st,table;
	for(int i=1;i<=n;i++) {
		int x,y;
		cin >> x >> y;
		for(int i=-2;i<=0;i++)
			for(int j=-2;j<=0;j++) {
				int nx = x + i , ny = y + j;
				if(nx >= 1 && ny >= 1 && nx+2 <= h && ny+2 <= w)
					st.insert(make_pair(nx,ny));
			}
		table.insert(make_pair(x,y));
	}
	
	ll ans[10] = {};
	for(pii p : st) {
		int cnt = 0;
		for(int i=0;i<=2;i++)
			for(int j=0;j<=2;j++)
				if(table.count(make_pair(p.first+i,p.second+j))==1)
					cnt++;
		ans[cnt]++;
	}
	ans[0] += (ll)(h-2)*(w-2) - (ll)st.size();
	for(int i=0;i<=9;i++)
		cout << ans[i] << endl;
	return 0;
}
