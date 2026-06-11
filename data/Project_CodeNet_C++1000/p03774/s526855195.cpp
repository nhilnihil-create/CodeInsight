#include<bits/stdc++.h>
using namespace std;
int main(){
	
	int n,m;cin>>n>>m;

	std::vector<pair<int,int>> a(n);
	std::vector<pair<int,int>> c(m);
	
	for(int i = 0; i < n; ++i)cin>>a[i].first>>a[i].second;
	for(int i = 0; i < m; ++i)cin>>c[i].first>>c[i].second;
	
	for(int i=0;i<n;i++){

		int x = a[i].first;
		int y = a[i].second;
		int dis = INT_MAX;
		int ans;
		for(int j=0;j<m;j++){
			int d = abs(x-c[j].first) + abs(y-c[j].second);
			// cout<<" For student "<<x<<" "<<y<<" "<<" cp: "<<j+1<<" Distance: "<<d<<endl;
			if( d<dis ){
				dis = d;
				ans = j+1;
			}
		}
		cout<<ans<<" "<<endl;
	}

	return 0;

}