#include<bits/stdc++.h>
using namespace std;
int f1[200000+10],f2[200000+10],n,k,l,x,y;
map<pair<int,int>,int > m;
int find(int x,int p[]){
	return p[x]==x?p[x]:p[x]=find(p[x],p);
}
void un(int x,int y,int p[]){
	if(find(x,p)!=find(y,p)){
		p[find(x,p)]=find(y,p);
	}
}
void init(int p[]){
	for(int i=1;i<=n;i++){
		p[i]=i;
	}	
}
int main(){
	cin>>n>>k>>l;
	init(f1);init(f2);
	for(int i=1;i<=k;i++){
		cin>>x>>y;
		un(x,y,f1);
	}
	for(int i=1;i<=l;i++){
		cin>>x>>y;
		un(x,y,f2);
	}
	for(int i=1;i<=n;i++){
		find(i,f1);find(i,f2);
	}
	for(int i=1;i<=n;i++){
		m[make_pair(f1[i],f2[i])]++;
	}
	for(int i=1;i<=n;i++){
		cout<<m[make_pair(f1[i],f2[i])]<<" ";
	}
	return 0;
}