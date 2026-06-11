#include <bits/stdc++.h>
using namespace std;
typedef pair <int,int> pii;

const int RLEN=1<<18|1;
inline char nc() {
	static char ibuf[RLEN],*ib,*ob;
	(ib==ob) && (ob=(ib=ibuf)+fread(ibuf,1,RLEN,stdin));
	return (ib==ob) ? -1 : *ib++;
}
inline int rd() {
	char ch=nc(); int i=0,f=1;
	while(!isdigit(ch)) {if(ch=='-')f=-1; ch=nc();}
	while(isdigit(ch)) {i=(i<<1)+(i<<3)+ch-'0'; ch=nc();}
	return i*f;
}

const int N=500*501;
int n,a[N],x[N],p[N];
multiset <pii> s;

int main() {
	n=rd();
	for(int i=1;i<=n;i++) {
		x[i]=rd();
		if(a[x[i]]) {puts("No"); exit(0);}
		a[x[i]]=i;  
		if(i!=1) s.insert(pii(x[i],i-1));
	}
	int head=1; while(a[head]) ++head;
	while(s.size()) {
		pii lim=*s.begin(); s.erase(s.begin());
		for(int j=1;j<=lim.second;++j) {
			if(head>lim.first) {puts("No"); exit(0);}
			a[head++]=lim.second+1;
			while(a[head]) ++head;
		}
	} s.clear(); 
	for(int i=1;i<=n;i++) s.insert(pii(x[i],n-i));
	while(s.size()) {
		pii lim=*s.begin(); s.erase(s.begin());
		if(head<=lim.first) {puts("No"); exit(0);}
		for(int j=1;j<=lim.second;++j) {
			a[head++]=n-lim.second;
			while(a[head]) ++head;
		}
	}
	puts("Yes");
	for(int i=1;i<=n*n;i++) printf("%d ",a[i]); 
}