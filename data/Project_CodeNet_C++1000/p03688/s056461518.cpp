#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
	while(c<'0'||c>'9'){ if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+c-'0',c=getchar();
	return x*f;
}
int n,a[1000006],k;
int main(){
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	sort(a+1,a+n+1);
	if(a[1]==a[n]){
		if(n-1==a[n]||(n/a[n])>=2) printf("Yes\n");
		else printf("No\n");	
	}
	else if(a[n]-a[1]==1){
		for(int i=1;i<=n;++i){
			if(a[i]==a[1]) ++k;
		}
		if(a[n]-k==0) printf("No\n");
		else if((n-k)/(a[n]-k)>=2) printf("Yes\n");
		else printf("No\n");
	}
	else{
		printf("No\n");
	}
	return 0;
}
