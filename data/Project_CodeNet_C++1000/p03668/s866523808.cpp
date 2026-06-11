#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
namespace io{
	const int L=(1<<19)+1;
	char ibuf[L],*iS,*iT,c;
	inline char Gc(){
		if(iS==iT){
			iT=(iS=ibuf)+fread(ibuf,1,L,stdin);
			return iS==iT?EOF:*iS++;
		}
		return*iS++;
	}
	template<class I>void Gi(I&x){
		for(c=Gc();c<'0'||c>'9';c=Gc());
		for(x=0;c<='9'&&c>='0';c=Gc())x=x*10+(c&15);
	}
};
using io::Gi;
int N,T;
struct edge{
	   int adj,nex;
	   edge (int a_=0,int n_=0){
			adj=a_;
			nex=n_;
	   }
}E[333333];
void add(int u,int v){
	   E[++T]=edge(v,E[u].nex);
	   E[u].nex=T;
	   E[++T]=edge(u,E[v].nex);
	   E[v].nex=T;
}
int dfs(int x,int f){
	int s=0;
	for (int i=E[x].nex;i;i=E[i].nex){
		if (E[i].adj!=f){
		   s^=(dfs(E[i].adj,x)+1);
		}
	}
	return s;
}
int main(){
	int u,v;
	Gi(N);
	T=N;
	for (int i=1;i!=N;i++){
		Gi(u);
		Gi(v);
		add(u,v);
	}
	printf(dfs(1,0)?"Alice":"Bob");
	return 0;
}