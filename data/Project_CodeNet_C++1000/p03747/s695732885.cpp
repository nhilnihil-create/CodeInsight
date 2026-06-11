#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>

int n,l,t;

int pos[100005];
int dir[100005];

ii fin[100005];

int norm(long long i,int j){
	i%=j;
	if (i<0) i+=j;
	return i;
}

main(){
	//freopen("input.txt","r",stdin);
	scanf("%d%d%d",&n,&l,&t);
	
	for (int x=0;x<n;x++){
		scanf("%d%d",&pos[x],&dir[x]);
	}
	
	for (int x=0;x<n;x++){
		if (dir[x]==1) fin[x]=ii(norm(pos[x]+t,l),x);
		else fin[x]=ii(norm(pos[x]-t,l),x);
	}
	
	sort(&fin[0],&fin[n],[](ii i,ii j){
		if (i.first!=j.first) return i.first<j.first;
		else return (i.second<j.second)==(dir[0]==2);
	});
	
	//for (int x=0;x<n;x++) printf("%d %d\n",fin[x].first,fin[x].second);
	
	long long shifts=0;

	t*=2;
	int tmp;
	for (int x=1;x<n;x++){
		if (dir[0]!=dir[x]){
			if (dir[0]==1) tmp=norm(pos[x]-pos[0],l);
			else tmp=norm(pos[0]-pos[x],l);
			
			if (tmp<=t) shifts+=1+(t-tmp)/l;
		}
	}
	
	if (dir[0]==1) shifts=norm(shifts,n);
	else shifts=norm(-shifts,n);
	
	//printf("%d\n",shifts);
	
	int startpos;
	for (int x=0;x<n;x++){
		if (fin[x].second==0) startpos=(x-shifts+n)%n;
	}
	//printf("%d\n\n",startpos);
	
	for (int x=0;x<n;x++) printf("%d\n",fin[(x+startpos)%n].first);
}
