#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define ll long long
using namespace std;
const int maxn=200010;
int pre[maxn*2],last[maxn],other[2*maxn],num,col[maxn];
bool vis[maxn],flag;
ll P,I,Q;
vector<int>V;
void add(int x,int y){
	num++;
	pre[num]=last[x];
	last[x]=num;
	other[num]=y;
}
int main(){
	int n,m;
	int x,y;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			queue<int>q; 
			q.push(i);
			col[i]=0;vis[i]=1;
			flag=1;
			V.clear();
			V.push_back(i);
			while(!q.empty()){
				int t=q.front();
				q.pop();
				for(int i=last[t];i;i=pre[i]){
					int v=other[i];
					if(!vis[v]){
						q.push(v);
						V.push_back(v);
						col[v]=col[t]+1;
						vis[v]=1;
					}
					else{
						if((col[v]-col[t])%2==0)
						flag=0;
					}
				}
			}
			if(V.size()==1) I++;
			else{
				if(flag) Q++;
				else P++;
			}
      	}	
	}
	ll ans=2*I*n-I*I+P*P+2*P*Q+2*Q*Q;
	printf("%lld\n",ans); 
	return 0;
}