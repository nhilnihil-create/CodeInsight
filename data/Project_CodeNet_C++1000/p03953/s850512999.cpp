#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,x[100050],a[100050],p[100050],s[100050],cnt,k;
int be[100050],num[100050];
bool vis[100050]={0};
vector<int>q[100050];
void dfs(int x,int dep){
	num[x]=dep,vis[x]=1,be[x]=cnt;
	q[cnt].push_back(x);
	if(!vis[p[x]]) dfs(p[x],dep+1);
}
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lld",&x[i]);
	}
	for(int i=1;i<n;i++){
		s[i]=x[i+1]-x[i];
	}
	cin>>m>>k;
	for(int i=1;i<n;i++) p[i]=i;
	for(int i=1;i<=m;i++){
		scanf("%lld",&a[i]);
		swap(p[a[i]],p[a[i]-1]);
	}
	for(int i=1;i<n;i++){
		if(!vis[i]){
			cnt++;
			dfs(i,0);
		}
	}
	cout<<x[1]<<endl;
	int now=x[1];
	for(int i=1;i<n;i++){
		now+=s[q[be[i]][(num[i]+k)%q[be[i]].size()]];
		cout<<now<<endl;
	}
	return 0;
}