#include<bits/stdc++.h>
using namespace std;

int n,id[100005],ans[100005],a[100005],tmp[100005],m;

long long k;

double output[100005];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",a+i),id[i]=ans[i]=i;
	//d[i]记录每只兔子跳一次之后下一次跳的位置，ans[i]记录跳完k轮之后每只兔子的位置
	scanf("%d%lld",&m,&k);
	for(int i=1,x;i<=m;i++){
		scanf("%d",&x);
		swap(id[x],id[x+1]);
	}
	while(k){
		if(k&1){
			for(int i=1;i<=n;i++) tmp[i]=ans[id[i]];
			for(int i=1;i<=n;i++) ans[i]=tmp[i];
		}
		for(int i=1;i<=n;i++) tmp[i]=id[id[i]];
		for(int i=1;i<=n;i++) id[i]=tmp[i];
		k>>=1;
	}
	for(int i=1;i<=n;i++) output[i]=(double)(a[ans[i]]-a[ans[i]-1]);
	for(int i=1;i<=n;i++) printf("%.1f\n",output[i]+=output[i-1]);
}