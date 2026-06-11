#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct hi{
	ll a;int b;
} cnt[200005];
int id[200005],id2[200005],p[200005]
,n,k,l,i,j,m;

int find(int x){
	while (x!=id[x]){
		id[x]=id[id[x]];
		x=id[x];
	}
	return x;
}

int find2(int x){
	while (x!=id2[x]){
		id2[x]=id2[id2[x]];
		x=id2[x];
	}
	return x;
}

void connect(int x,int y){
	x=find(x);y=find(y);
	if (x!=y) id[x]=y;
}

void connect2(int x,int y){
	x=find2(x);y=find2(y);
	if (x!=y) id2[x]=y;
}

bool cmp(hi a,hi b){
	return a.a<b.a;
}

int main(){
	scanf("%d%d%d",&n,&k,&l);
	for (i=1;i<=n;i++){
		id[i]=i;id2[i]=i;
	}
	for (i=1;i<=k;i++){
		scanf("%d%d",&j,&m);
		connect(j,m);
	}
	for (i=1;i<=l;i++){
		scanf("%d%d",&j,&m);
		connect2(j,m);
	}
	for (i=1;i<=n;i++){
		id[i]=find(id[i]);id2[i]=find2(id2[i]);
		cnt[i].a=ll(id[i])*200001+ll(id2[i]);cnt[i].b=i;
	}
	sort(cnt+1,cnt+n+1,cmp);
	j=0;k=0;
	for (i=1;i<=n;i++){
		if (cnt[i].a!=cnt[i-1].a) j++;
		p[j]++;
		id[cnt[i].b]=j;
	}
	for (i=1;i<n;i++) printf("%d ",p[id[i]]);
	printf("%d\n",p[id[n]]);
}