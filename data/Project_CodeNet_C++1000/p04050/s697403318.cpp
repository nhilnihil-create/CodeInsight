#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<cstdio>
#include<algorithm>
using namespace std;

#define LL long long

inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}
const int INF=9999999;
const int MAXN=300010;

int N,M;
int a[MAXN+1]; 
int ans[MAXN+1],sta[MAXN+1],ge[MAXN+1];
int cnt,cnt3,cnt2;

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	N=read(),M=read();
	for(int i=1;i<=M;i++) {
		a[i]=read();
		if(a[i]&1) sta[++cnt]=a[i];
		else ge[++cnt2]=a[i];
	}
	if(cnt>2) {puts("Impossible"); return 0;}
	if(cnt) ans[++cnt3]=sta[cnt--];
	for(int i=1;i<=cnt2;i++) ans[++cnt3]=ge[i];
	if(cnt) ans[++cnt3]=sta[cnt--];
	for(int i=1;i<=cnt3;i++) printf("%d ",ans[i]);
	ans[1]++; ans[cnt3]--; puts("");
	if(cnt3>1){
		if(!ans[cnt3]) --cnt3;
		printf("%d\n",cnt3);
		for(int i=1;i<=cnt3&&ans[i];i++) printf("%d ",ans[i]);
	}
	else {
		if(N&1){
			printf("%d\n",(N+1)>>1);
			for(int i=1;i<=(N>>1);i++) printf("%d ",2);
			printf("%d\n",1);
		}
		else {
			cnt3=0; int now=1;
			ans[++cnt3]=1;
			if((N>>1)&1){
				while(now<(N>>1)){
					now+=2; ans[++cnt3]=2;
				} printf("%d\n",cnt3*2);
				for(int i=1;i<=cnt3;i++){
					printf("%d ",ans[i]);
				}
				for(int i=1;i<=cnt3;i++){
					printf("%d ",ans[i]);
				}
			}
			else{
				while(now<(N>>1)-1){
					now+=2; ans[++cnt3]=2;
				} printf("%d\n",cnt3*2+1);
				for(int i=1;i<=cnt3;i++){
					printf("%d ",ans[i]);
				}
				for(int i=1;i<=cnt3;i++){
					printf("%d ",ans[i]);
				} printf("%d\n",2);
			}
		}
	}
	return 0;
}
