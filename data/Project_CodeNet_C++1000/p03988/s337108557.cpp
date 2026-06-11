#include<bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
const int N=109;
int a[N],b[N],n,mx;
int rd(){
	char ch=getchar();int x=0;
	while(ch<48||ch>57)ch=getchar();
	while(ch>47&&ch<58)
		x+=(x<<3)+x+ch-48,ch=getchar();
	return x;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		a[i]=rd(),mx=max(mx,a[i]),++b[a[i]];
	if(mx&1){
		for(int i=mx;i>=(mx+1)/2;--i)
			if(b[i]<2)puts("Impossible"),exit(0);
		for(int i=1;i<(mx+1)/2;++i)
			if(b[i])puts("Impossible"),exit(0);
		if(b[(mx+1)/2]>2)
			puts("Impossible"),exit(0);
	}
	else{
		for(int i=mx;i>mx/2;--i)
			if(b[i]<2)puts("Impossible"),exit(0);
		for(int i=1;i<mx/2;++i)
			if(b[i])puts("Impossible"),exit(0);
		if(b[mx/2]^1)puts("Impossible"),exit(0);
	}
	puts("Possible"),exit(0);
}