#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define lol(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
typedef long long ll;
using namespace std;
vector<int> child[100010];
int p[100010];
int vis[100010];
typedef pair<int,int> P;
queue<P>Q;
priority_queue<P>PQ;
void Kill(int x){
	if(vis[x]==0)return;
	vis[x]=0;
	int siz=child[x].size();
	lol(i,siz){
		Kill(child[x][i]);
	}
}
int Ancestor(int x,int len){
	if(len==0)return x;
	return Ancestor(p[x],len-1);
}
int main(){
	int n,k,ans=0;
	cin>>n>>k;
	lol(i,n){
		int a;cin>>a;a--;
		if(i==0&&a>0)ans++;
		p[i]=a;
		child[a].push_back(i);
		vis[i]=mod;
	}
	Q.push(make_pair(0,0));
	while(!Q.empty()){
		int x=Q.front().first;
		int len=Q.front().second;
		Q.pop();
		if(vis[x]!=mod)continue;
		vis[x]=len;
		int siz=child[x].size();
		lol(i,siz){
			int to=child[x][i];
			Q.push(make_pair(to,len+1));
		}
	}
	lol(i,n)PQ.push(make_pair(vis[i],i));
	while(!PQ.empty()){
		int len=PQ.top().first;
		int x=PQ.top().second;
		PQ.pop();
		if(len<=k)break;
		if(vis[x]!=len)continue;
		x=Ancestor(x,k-1);
		Kill(x);
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}
