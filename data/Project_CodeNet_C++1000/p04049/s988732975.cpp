#include<bits/stdc++.h>
#define re register
#define inc(i,j,k) for(re int i=j;i<=k;i++)
using namespace std;
const int N=2005;
inline int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while('0'<=ch&&ch<='9') x=x*10+ch-'0',ch=getchar(); 
	return x;
}
int n,k,a[N],b[N],ans,res;
vector<int> to[N];
void get(int u,int f,int d){
	if(d>k/2) res++;
	for(re int i=0;i<to[u].size();i++){
		int v=to[u][i];
		if(v==f) continue;
		get(v,u,d+1);
	}
}
int main(){
	n=read(),k=read();ans=n;
	inc(i,2,n){
		a[i]=read(),b[i]=read();
		to[a[i]].push_back(b[i]);
		to[b[i]].push_back(a[i]);
	}
	if(k&1){
		inc(i,2,n) res=0,get(a[i],b[i],0),get(b[i],a[i],0),ans=min(ans,res);
	}
	else{
		inc(i,1,n) res=0,get(i,0,0),ans=min(ans,res);
	}
	printf("%d",ans);
}