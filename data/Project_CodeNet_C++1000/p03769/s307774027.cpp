#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;
ll n;int now=0;
vector<int> ans;
void dfs(ll n){
	if(n==1) return;
	if(n&1){
		dfs(n^1);
		ans.insert(ans.begin(),++now);
		return;
	}
	dfs(n>>1);
	ans.push_back(++now);
}
int main(){
	scanf("%lld",&n);
	dfs(n+1);
	printf("%d\n",ans.size()*2);
	for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);
	for(int i=1;i<=now;i++) printf((i==now)?"%d":"%d ",i);
	return 0;
}