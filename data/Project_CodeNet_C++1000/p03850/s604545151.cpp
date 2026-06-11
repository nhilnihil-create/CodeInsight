#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
long long n,a[120000],b[120000],x,tail,tot;
char s[10]; 
int main(){
	scanf("%lld",&n);
	scanf("%lld",&a[1]);
	tail=1;
	tot=a[1];
	for(int i=2;i<=n;i++){
		scanf("%s",s+1);
		scanf("%lld",&x);
		tot+=x;
		if(s[1]=='-'){
			tail++;
			a[tail]=x;
			b[tail]=x;
		}else a[tail]+=x;
	}
	long long ans=1000000000000000000LL,bns=0;
	for(int i=2;i<=tail;i++){
		ans=min(ans,bns+a[i]);
		bns+=b[i];
	}
	if(tail==1)ans=0;
	printf("%lld\n",tot-2*ans);
}