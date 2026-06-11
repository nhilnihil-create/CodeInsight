#include <bits/stdc++.h>
using namespace std;

namespace IO {
	inline char gc(){
		static char buf[1<<20],*p1=buf,*p2=buf;
		if(p1==p2){
			p2=(p1=buf)+fread(buf,1,1<<20,stdin);
			if(p1==p2) return EOF;
		}
		return *p1++;
	}

	#define gc getchar
	
	inline int read(){
		int x=0;bool f=0;char p=gc();
		while(!isdigit(p)) f|=(p=='-'),p=gc();
		while(isdigit(p)) x=x*10+p-'0',p=gc();
		return (f)?-x:x;
	}

}

int n;
const int N=1e5+5;
int a[N];

bool cmp(int a,int b){
	return a>b;
}

int main(){
//	freopen("t1.in","r",stdin);
//	freopen("t1.out","w",stdout);
//	int T=IO::read();
	int T=1;
	while(T--){
		n=IO::read();
		for(int i=1;i<=n;++i) 
			a[i]=IO::read();
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;++i)
			if(a[i+1]<i+1){
				int r=i+1;
				while(a[r]==i) r++;
				if(((r-i+1)&1) || ((a[i]-i)&1)) puts("First");
				else puts("Second");
				break;
			}
	}
	return 0;
}
/*
1
2
1 3
*/