#include <bits/stdc++.h>
using namespace std;
const int N=100010;
int n,t;
int a[N];
int main(){
	scanf("%d%d",&n,&t);
	for (int i=1; i<=n; ++i) scanf("%d",&a[i]);
	set<int> s;
	int ans=0;
	for (int i=1; i<=n; ++i){
	if (s.size()){
		ans=max(ans,a[i]-(*s.begin()));
	}
	s.insert(a[i]);
	}
	s.clear();
	int rig=0,lef=0;
	for (int i=1; i<=n; ++i){
	if (s.size()){
		if (a[i]-(*s.begin())==ans) ++rig;
	}
	s.insert(a[i]);
	}
	s.clear();
	for (int i=n; i>=1; --i){
	if (s.size()){
		if ((*s.rbegin()-a[i])==ans) ++lef;
	}
	s.insert(a[i]);
	}
	cout<<min(lef,rig);
}