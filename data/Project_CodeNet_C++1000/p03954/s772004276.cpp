#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int N=2e5+5;
int n,m,a[N],b[N];
vector < pair < pair < int , int > , int > > v;	
bool check(int x) {
	for (int i=1; i<=m; i++) 
		if (a[i]>=x) b[i]=1;
				else b[i]=0;
		
	int len=2,l=0;	
	b[m+1]=-1,b[0]=0;

	v.clear();
	for (int i=1; i<=m+1; i++) {
		if (b[i]!=b[i-1] || i==1) {
			if (len>1) v.push_back({{l,i-1},b[l]});
			len=1;
			l=i;
		}
			else len++;
	}
	
	if (v.size()==1) return b[1];
	v.push_back({{m+1,m+1},0});
	
	for (int i=1; i<v.size(); i++) {
		int l=v[i-1].F.S+1;
		int r=v[i].F.F-1;
		if (l<=r) {
			int mid=(l+r)/2;
			v[i-1].F.S=mid;
			v[i].F.F=mid+1;
		}
	}

	for (int i=1; i<v.size()-1; i++) 
		if (v[i].F.F<=n && n<=v[i].F.S) return v[i].S;
}

main ()  {
	ios::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	
	cin>>n;
	m=2*n-1;
	for (int i=1; i<=m; i++) 
		cin>>a[i];
	
	int l=1,r=m,mid,ans=-1;
	
	while (l<=r) {
		mid=(l+r)/2;
		if (check(mid)) { l=mid+1; ans=mid; }
			else r=mid-1;
	}
	
	cout<<ans<<"\n";
}