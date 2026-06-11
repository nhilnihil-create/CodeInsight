#include<cstdio>
#include<cstring>
#include<algorithm>
const int N=200005;
int n,m,u,v,t1,t2,t3,cnt,head[N],dep[N],to[N*2],nxt[N*2];
bool vis[N];
char ch[2500005],*p=ch;
inline int rd(){
	register int res=0;
	while(*p<'0'||*p>'9'){
		p++;
	}
	while(*p>='0'&&*p<='9'){
		res=res*10+*p-'0';
		p++;
	}
	return res;
}
void adde(int u,int v){
	to[++cnt]=v;
	nxt[cnt]=head[u];
	head[u]=cnt;
}
bool dfs(int u){
	vis[u]=true;
	int v;
	bool flag=true;
	for(int i=head[u];i;i=nxt[i]){
		v=to[i];
		if(!vis[v]){
			dep[v]=dep[u]+1;
			if(!dfs(v)){
				flag=false;
			}
		}else if(~(dep[u]-dep[v])&1){
			flag=false;
		}
	}
	return flag;
}
int main(){
	fread(ch,1,2500000,stdin);
	n=rd(),m=rd();
	for(int i=1;i<=m;i++){
		u=rd(),v=rd();
		adde(u,v);
		adde(v,u);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			if(!head[i]){
				vis[i]=true;
				t1++;
			}else if(dfs(i)){
				t2++;
			}else{
				t3++;
			}
		}
	}
	printf("%lld\n",1LL*t1*t1+2LL*t1*(n-t1)+2LL*t2*t2+2LL*t2*t3+1LL*t3*t3);
	return 0;
}