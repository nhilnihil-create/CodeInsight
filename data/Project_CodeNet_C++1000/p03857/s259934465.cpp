#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int N = 200005;
int n,x,y,ans[N];
// road
int k, knm[N],kfa[N];

int kfind(int t){
	if(t == kfa[t]) return t;
	return kfa[t] = kfind(kfa[t]);
}
// raiway
int l, lnm[N],lfa[N];
int lfind(int t){
	if(t == lfa[t]) return t;
	return lfa[t] = lfind(lfa[t]);
}

map<pair<int, int>, int> mp;

int main(){
	scanf("%d%d%d",&n,&k,&l);
	// k
	for(int i=1;i<=n;++i)
		kfa[i] = i;
	for(int i=1;i<=k;++i){
		scanf("%d%d",&x,&y);
		int tx = kfind(x), ty = kfind(y);
		if(tx != ty)
			kfa[ty] = tx;
	}
	
	// l
	for(int i=1;i<=n;++i)
		lfa[i] = i;	
	for(int i=1;i<=l;++i){
		scanf("%d%d",&x,&y);
		int tx = lfind(x), ty = lfind(y);
		if(tx != ty)
			lfa[ty] = tx;
	}
	
//for(int i=1;i<=n;++i)
//		cout<<lfa[i]<<" ";
//	cout<<endl;
	//cout<<kfa[3]<<" "<<lfa[3]<<endl;
	//cout<<kfa[5]<<" "<<lfa[5]<<endl;
	
	for(int i=1;i<=n;++i){
		++ mp[make_pair(kfind(i), lfind(i))];
	}
	for(int i=1;i<=n;++i)
		ans[i] = mp[make_pair(kfind(i), lfind(i))];
	for(int i=1;i<n;++i)
		printf("%d ", ans[i]);
	printf("%d\n", ans[n]); 
}