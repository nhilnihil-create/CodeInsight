#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int n,m;cin>>n>>m;
	vector<pair<int,int> >std;
	for(int i=0;i<n;i++){
		int a,b;cin>>a>>b;
		std.push_back({a,b});
	}
	vector<pair<int,int> > pts;
	for(int i=0;i<m;i++){
		int x,y;cin>>x>>y;
		pts.push_back({x,y});
	}
	for(int i=0;i<n;i++){
		int mn=1e9;
		int ind;
		for(int j=m-1;j>=0;j--){
			int now=abs(std[i].first-pts[j].first)+abs(std[i].second-pts[j].second);
			if(now<=mn){
				mn=now;
				ind=j+1;
			}
		}
		cout<<ind<<endl;
	}
	return 0;
}