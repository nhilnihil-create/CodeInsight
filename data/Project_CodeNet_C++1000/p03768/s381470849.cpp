#include<bits/stdc++.h>
using namespace std;
#define nn 500008
vector<int> v[nn];
struct jack{
	int si,di,co,when;
	jack(int a=0,int b=0,int c=0,int d=0){
		si=a,di=b,co=c;when=d;
	}
};
bool operator<(jack a,jack b){
	if(a.di!=b.di) return a.di<b.di;
	return a.when<b.when;
}
int color[nn],when[nn];

int n,m,q;
int si[nn],di[nn],co[nn];

signed main(){
	scanf("%d%d",&n,&m);
	while(m--){
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].push_back(y),v[y].push_back(x);
	}
	
	scanf("%d",&q);
	priority_queue<jack> pq;
	for(int i=1;i<=q;i++) scanf("%d%d%d",&si[i],&di[i],&co[i]),pq.push(jack(si[i],di[i],co[i],i));
	while(pq.size()){
		jack x=pq.top();pq.pop();
		if(when[x.si]<x.when){
			when[x.si]=x.when;
			color[x.si]=x.co;
		}
		else continue;

		for(int i=0;i<v[x.si].size();i++)if(x.di){
			int y=v[x.si][i];
			if(when[y]<x.when)
				pq.push(jack(y,x.di-1,x.co,x.when));
		}
	}
	
	for(int i=1;i<=n;i++) printf("%d\n",color[i]);
	
	return 0;
}