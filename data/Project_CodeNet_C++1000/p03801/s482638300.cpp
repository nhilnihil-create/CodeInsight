#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef pair<int,int> ii;
typedef pair<ii,int> iii;

const int MAX=1e5+5;

int n,f[MAX];
ii a[MAX];
vector<iii> V;

int32_t main() {
	//freopen("input","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i].first;
		a[i].second=i;
	}
	sort(a+1,a+n+1);
	V.push_back({a[1],1});
	for(int i=2;i<=n;i++)
		if(a[i].first>a[i-1].first)
			V.push_back({a[i],1});
		else
			V.back().second++;
	int minId=1e9,cnt=0;
	for(int i=V.size()-1;i>=0;i--) {
		minId=min(minId,V[i].first.second);
		cnt+=V[i].second;
		f[minId]+=(V[i].first.first-(i==0?0:V[i-1].first.first))*cnt;
	}
	for(int i=1;i<=n;i++)
		cout<<f[i]<<'\n';
}
