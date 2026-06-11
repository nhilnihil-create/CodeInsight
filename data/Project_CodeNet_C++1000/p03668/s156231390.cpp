#include <bits/stdc++.h>
using namespace std;

const int RLEN=1<<18|1;
inline char nc() {
	static char ibuf[RLEN],*ib,*ob;
	(ib==ob) && (ob=(ib=ibuf)+fread(ibuf,1,RLEN,stdin));
	return (ib==ob) ? -1  : *ib++;
}
inline int rd() {
	char ch=nc(); int i=0,f=1;
	while(!isdigit(ch)) {if(ch=='-')f=-1; ch=nc();}
	while(isdigit(ch)) {i=(i<<1)+(i<<3)+ch-'0'; ch=nc();}
	return i*f;
}

const int N=1e5+50;
int n;
vector <int> edge[N];

inline int sg(int x,int f) {
	int sum=0;
	for(auto v:edge[x])
		if(v^f) sum^=(sg(v,x)+1);
	return sum;
}
int main() {
	n=rd();
	for(int i=1;i<n;i++) {
		int x=rd(), y=rd();
		edge[x].push_back(y);
		edge[y].push_back(x);
	} puts(sg(1,0) ? "Alice" : "Bob");
}