#include<bits/stdc++.h>
using namespace std;
int n;
#define ran 222222
struct graph{
	int id[ran];
	int ancestor(int x){return x-id[x]?id[x]=ancestor(id[x]):x;}
	void init(int m){
		for(int i=1; i<=n; i++)
			id[i] = i;
		while(m--){
			int x,y;
			scanf("%d%d",&x,&y);
			id[ancestor(x)] = ancestor(y);
		}
		for(int i=1; i<=n; i++)
			ancestor(i);
	}
} g1,g2;
map<pair<int,int>,int> Map;
int main(){
	int m1,m2;
	scanf("%d%d%d",&n,&m1,&m2);
	g1.init(m1);
	g2.init(m2);
	for(int i=1; i<=n; i++){
		Map[make_pair(g1.id[i],g2.id[i])]++;
	}
	for(int i=1; i<=n; i++)
		printf("%d%c",Map[make_pair(g1.id[i],g2.id[i])],i<n?' ':'\n');
	return 0;
}
