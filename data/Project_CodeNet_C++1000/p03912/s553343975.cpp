#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;

int n,m;
vector<int> li[N+5];
set<int> dup;
int cnt[N+5];

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int x; 
		scanf("%d",&x);
		int lol = x%m;
		li[lol].push_back(x);
		if(dup.find(x) == dup.end()){
			dup.insert(x);
		} else {
			dup.erase(x);
			cnt[lol]++;
		}
	}
	int ans = li[0].size()/2;
	for(int i=1;;i++){
		int butuh = m-i;
		if(butuh < i) break;
		if(butuh == i){
			ans+=li[i].size()/2;
			continue;
		}
		ans += min(li[i].size(),li[butuh].size());
		if(li[i].size() > li[butuh].size()){
			int tmp = li[i].size() - li[butuh].size();
			ans+=min(cnt[i],tmp/2);
		} else {
			int tmp = li[butuh].size() - li[i].size();
			ans+=min(cnt[butuh],tmp/2);
		}
	}
	printf("%d\n",ans);
	return 0;
}