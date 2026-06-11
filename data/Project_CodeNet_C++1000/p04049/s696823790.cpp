#include<bits/stdc++.h>
#define rint register int
#define ll long long
#define pa pair<int,int>
using namespace std;
struct node{int to,next;} e[1010100];
int h[1010100],tot,N,K,dep[2020],sz,fl;
pa tmp[110100];
inline void add(int from,int to){e[++tot].next=h[from];h[from]=tot;e[tot].to=to;}
inline void DFS(int now,int ffa){
	for(rint i=h[now];i;i=e[i].next){
		int to=e[i].to;if(to==ffa) continue;
		dep[to]=dep[now]+1;
		if(K&1){
			if(dep[to]<=K/2) sz++;
			else if(dep[to]==(K+1)/2) {
				if(!fl) fl=1,sz++;
			}
		} 
		else if(dep[to]<=K/2) sz++;
		DFS(to,now);
	}
}
inline int Get_ans(int center){
	memset(dep,0,sizeof(dep));sz=fl=0;
	DFS(center,0);
	sz++;
	return N-sz;
}
inline void DFS2(int now,int ffa){
	if(dep[now]<=(K-1)/2) sz++;
	for(rint i=h[now];i;i=e[i].next){
		int to=e[i].to;if(to==ffa) continue;
		dep[to]=dep[now]+1;DFS2(to,now);
	}
}
int main(){
	cin>>N>>K;
	if(K==1) {
		cout<<N-2<<endl;
		return 0;
	}
	if(K>=N-1) {
		cout<<0<<endl;
		return 0;
	}
	for(rint i=1;i<N;++i){
		int a,b;cin>>a>>b;
		add(a,b);add(b,a);
		tmp[i].first=a,tmp[i].second=b;
	}int ans=1e9;
	if(K&1) {
		for(rint i=1;i<N;++i) {
			int a=tmp[i].first,b=tmp[i].second;
			sz=0;
			memset(dep,0,sizeof(dep));
			DFS2(a,b);
			DFS2(b,a);
			ans=min(ans,N-sz);
		}cout<<ans;
		return 0;
	}
	
	for(rint i=1;i<=N;++i){
		ans=min(ans,Get_ans(i));
	}cout<<ans;
	return 0;
} 