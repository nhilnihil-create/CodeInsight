#include<bits/stdc++.h>
#define ll long long
using namespace std;
int ans,n,m,cnt,f[6000010],ch[6000010][2],rt[500010];
vector<int>zh[500010];
void ins(int &x,int la,int l,int r,int t){
	x=++cnt;f[x]=f[la]+1;
	ch[x][0]=ch[la][0];ch[x][1]=ch[la][1];
	if(l==r)return;
	int mid=(l+r)/2;
	if(mid>=t)ins(ch[x][0],ch[la][0],l,mid,t);
	 else ins(ch[x][1],ch[la][1],mid+1,r,t);
}
int query(int x,int l,int r,int t,int k){
	if(!x)return 0;
	if(l==t&&r==k)return f[x];
	int mid=(l+r)/2;
	if(mid>=k)return query(ch[x][0],l,mid,t,k);
	 else if(t>mid)return query(ch[x][1],mid+1,r,t,k);
	  else return query(ch[x][0],l,mid,t,mid)+query(ch[x][1],mid+1,r,mid+1,k);
}
int main(){
	int i,x,y,j,nt;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d%d",&x,&y);
		zh[y].push_back(x);
	}
	for(i=1;i<=m;i++){
		rt[i]=++cnt;ch[rt[i]][0]=ch[rt[i-1]][0];ch[rt[i]][1]=ch[rt[i-1]][1];
		f[rt[i]]=f[rt[i-1]];
		for(j=0;j<zh[i].size();j++){
			x=zh[i][j];
			ins(rt[i],rt[i],1,m,x);
		}
	}
	for(i=1;i<=m;i++){
		ans=0;
		for(j=i;j<=m;j+=i){
			nt=min(m,j+i-1);
			ans=ans+query(rt[nt],1,m,1,j)-query(rt[j-1],1,m,1,j);
		}
		printf("%d\n",ans);
	}
}