#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int N=100005; 

using namespace std;

int n; 
int a[N],nxt[N];
long long s[N];  
char opt[N]; 

int main(){
	int mk;
	long long cnt,ans;  
	scanf("%d",&n); 
	scanf("%d",&a[1]);
	opt[1]='+'; 
	for(int i=2; i<=n; ++i){
		scanf("\n%c",&opt[i]); 
		scanf("%d",&a[i]); 
	}
	s[n+1]=0; 
	for(int i=n; i>=1; --i) s[i]=s[i+1]+a[i]; 
	mk=n+1;
	for(int i=n; i>=1; --i){
		nxt[i]=(mk==n+1)?i:mk; 
		mk=(opt[i]=='-')?i:mk;
	}
	cnt=0;
	ans=-1ll<<60; 
	for(int i=1; i<=n; ++i){
		if(opt[i]=='-'){
			if(nxt[i]!=i) ans=max(ans,cnt+s[nxt[i]]-(s[i]-s[nxt[i]])); 	
			else ans=max(ans,cnt-s[nxt[i]]); 
		}
		cnt+=(opt[i]=='+')?a[i]:-a[i]; 
	}
	ans=max(ans,cnt); 
	printf("%lld\n",ans); 
	return 0; 
}