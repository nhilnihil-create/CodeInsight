#include<bits/stdc++.h>
using namespace std;
int n,a[100005],m1,m2;

int read(){
	int x=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x;
}

void fuck(){
	puts("No");exit(0);
}

void shit(){
	puts("Yes");exit(0);
}

int main(){
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	m1=m2=a[1];
	for(int i=2;i<=n;i++) m1=max(m1,a[i]),m2=min(m2,a[i]);
	if(m1>m2+1) fuck();
	if(m1==m2){
		if(2*m1<=n||m1==n-1) shit();
		else fuck();
	}
	if(m1!=m2){
		int ge=0;
		for(int i=1;i<=n;i++) if(a[i]==m2) ge++;
		if(2*(m1-ge)<=n-ge&&m1-ge>0) shit();
		else fuck();
	}
	
	return 0;
}