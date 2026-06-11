#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
	int x,y;
}a[20005];
vector<int> vec[20005];
int n,k,x,y,ans,sum;
int dfs(int pos,int fa,int dep){
	if(dep>k/2)	sum++;
	for(int i=0;i<vec[pos].size();i++){
		if(vec[pos][i]==fa) continue;
		dfs(vec[pos][i],pos,dep+1);
	}
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		a[i].x=x;a[i].y=y;
		vec[x].push_back(y);
		vec[y].push_back(x);
	}ans=n;
	if(!(k%2)){
		for(int i=1;i<=n;i++){
			sum=0;
			dfs(i,-1,0);
			ans=min(ans,sum);
		}
	}
	else{
		for(int i=1;i<n;i++){
			sum=0;
			dfs(a[i].x,a[i].y,0);
			dfs(a[i].y,a[i].x,0);
			ans=min(ans,sum);
		}
	}
	printf("%d\n",ans);
}