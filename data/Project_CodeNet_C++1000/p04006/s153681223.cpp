#include <bits/stdc++.h>
using namespace std;

struct node{
	int s,e,m;
	long long v;
	node *l,*r;
	node(int S,int E){
		s=S;e=E;m=(s+e)/2;v=0;
		if(s!=e){
			l=new node(s,m),r=new node(m+1,e);
		}
	}
	void upd(int x,long long nv){
		if(s==e){v=nv;return;}
		if(x<=m)l->upd(x,nv);
		else r->upd(x,nv);
		v=min(l->v,r->v);
	}
	long long qry(int x,int y){
		if(s==x&&e==y)return v;
		if(y<=m)return l->qry(x,y);
		if(x>m)return r->qry(x,y);
		return min(l->qry(x,m),r->qry(m+1,y));
	}
}*root;

int main(){
	int n; long long x;
	scanf("%d%lld",&n,&x);
	root=new node(0,n*2);
	long long arr[n];
	for(int i=0;i<n;i++){scanf("%lld",&arr[i]);root->upd(i,arr[i]);root->upd(i+n,arr[i]);}
	long long ans=1012345678012345678LL;
	for(int i=0;i<n;i++){
		long long cur=0;
		for(int j=0;j<n;j++){
			cur+=root->qry(j,j+i);
		}
		ans=min(ans,cur+(long long)(i)*x);
	}
	printf("%lld",ans);
}
