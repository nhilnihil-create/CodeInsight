#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int N=6666666;
int n;
pair<int,int>X[N];
queue<int>q;
bool vis[N];
int ans[N];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	scanf("%d",&X[i].first),X[i].second=i;
	sort(X+1,X+n+1);
	for(int i=1;i<=n;++i){
		for(int j=X[i-1].first+1;j<X[i].first;++j)q.push(j);
		ans[X[i].first]=X[i].second;
		vis[X[i].first]=1;
		for(int j=1;j<X[i].second;++j){
			if(q.empty()){puts("No");return 0;}
			int u=q.front();q.pop();
			vis[u]=1,ans[u]=X[i].second;
		}
	}
	while(!q.empty())q.pop();
	X[n+1].first=n*n+1;
	for(int i=n;i;--i){
		for(int j=X[i+1].first-1;j>X[i].first;--j)if(!vis[j])q.push(j);
		for(int j=1;j<=n-X[i].second;++j){
			if(q.empty()){puts("No");return 0;}
			int u=q.front();q.pop();
			vis[u]=1,ans[u]=X[i].second;
		}
	}
	puts("Yes");
	for(int i=1;i<=n*n;++i)
	printf("%d ",ans[i]);
	return 0;
}