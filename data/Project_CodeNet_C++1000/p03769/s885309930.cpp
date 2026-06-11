#include<bits/stdc++.h>
#define ll long long
using namespace std;
int u=101,hd[101],tl[101],ct1,ct2;ll n;
int main(){
	scanf("%lld",&n);++n;
	while(n>1){
		if(n&1) hd[++ct1]=--u,n--;
		else tl[++ct2]=--u,n>>=1;
	}printf("%d\n",(ct1+ct2)<<1);
	for(int i=1;i<=ct1;i++) printf("%d ",hd[i]);
	for(int i=ct2;i>=1;i--) printf("%d ",tl[i]);
	for(int i=u;i<=100;i++) printf("%d ",i);
	return 0;
}