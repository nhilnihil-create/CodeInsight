#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 10010
using namespace std;
int n,k,a[N],f[N],ok=1,s;
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),a[i]=min(a[i],k),s+=a[i];
	sort(a+1,a+n+1);
	f[0]=1;
	for(int i=n;i>=0;i--){
		ok=1;
		for(int j=max(k-s,0);j<=k-1;j++) 
	        if(f[j]==1) {ok=0;break;}
	    if(ok){
	    	printf("%d",i);
	    	break;
	    }
	    for(int j=k;j>=a[i];j--) f[j]=f[j-a[i]]|f[j];
	    s-=a[i];
	} 
}/*
6 3
10 4 3 10 25 2
*/