#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAX=2e5+5;
int n,k,a[MAX],tree[MAX];

void update(int idx) {
	while(idx<=n+1) {
		tree[idx]++;
		idx+=idx&-idx;
	}
}

int query(int idx) {
	int rs=0;
	while(idx>0) {
		rs+=tree[idx];
		idx-=idx&-idx;
	}
	return rs;
}

int32_t main() {
	//freopen("input","r",stdin);
	cin>>n>>k;
	vector<int> V;
	map<int,int> M;
	V.push_back(0);
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		a[i]+=a[i-1]-k;
		V.push_back(a[i]);
	}
	sort(V.begin(),V.end());
	V.resize(unique(V.begin(),V.end())-V.begin());
	int cnt=0;
	for(int x:V)
		M[x]=++cnt;
	int rs=0;
	update(M[0]);
	for(int i=1;i<=n;i++) {
		rs+=query(M[a[i]]);
		update(M[a[i]]);
	}
	cout<<rs;
}
