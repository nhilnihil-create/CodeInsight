#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<stack>
#include<queue>
using namespace std;
typedef long long ll;

const int maxn = 2020;

int n,m,tr;
ll d[maxn],d1,d2;

struct E{
	int from,to;
	ll cost;
}e[maxn]; 

ll read(){ ll s=0,f=1; char ch=getchar(); while(ch<'0' || ch>'9'){ if(ch=='-') f=-1; ch=getchar(); } while(ch>='0' && ch<='9'){ s=s*10+ch-'0'; ch=getchar(); } return s*f; }

int main(){
	memset(d,0x3f,sizeof(d)); 
	tr=1;
	n=read(),m=read(); 
	for(int i=1;i<=m;i++){
		e[i].from = read();
		e[i].to = read();
		e[i].cost = read();
		e[i].cost *= -1;
	}
	
	d[1] = 0 ;
//	for(int i=1;i<=m;i++) printf("%lld ",e[i].cost); printf("\n");
	
	for(int i=1;i<=n-1;i++){
		for(int j=1;j<=m;j++){
			if(d[e[j].from] + e[j].cost < d[e[j].to]) 
				d[e[j].to] = d[e[j].from] + e[j].cost;
		}
	}
	d1 = d[n];
	
	for(int i=1;i<=n-1;i++){
		for(int j=1;j<=m;j++){
			if(d[e[j].from] + e[j].cost < d[e[j].to]) 
				d[e[j].to] = d[e[j].from] + e[j].cost;
		}
	}
	
	d2 = d[n];

	if(d1 == d2){
		printf("%lld\n",d[n]*(-1));
	}else{
		printf("inf\n");
	}
	
	return 0;
}