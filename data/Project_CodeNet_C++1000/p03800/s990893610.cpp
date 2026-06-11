#include <bits/stdc++.h>
using namespace std; 
#define N 100010
int n,a[N];
char str[N];
inline bool check(){
	for(int i=2;i<n;++i){
		if(a[i]==0){
			if(str[i]=='o') a[i+1]=a[i-1];
			else a[i+1]=a[i-1]^1;
		}else {
			if(str[i]=='o') a[i+1]=a[i-1]^1;
			else a[i+1]=a[i-1];
		}
	}
	if(a[1]==0){
		if(str[1]=='o'){
			if(a[2]!=a[n]) return false;
		}else{
			if(a[2]==a[n]) return false;
		}
	}else{
		if(str[1]=='o'){
			if(a[2]==a[n]) return false;
		}else{
			if(a[2]!=a[n]) return false;
		}
	}
	if(a[n]==0){
		if(str[n]=='o'){
			if(a[1]!=a[n-1]) return false;
		}else{
			if(a[1]==a[n-1]) return false;
		}
	}else{
		if(str[n]=='o'){
			if(a[1]==a[n-1]) return false;
		}else{
			if(a[1]!=a[n-1]) return false;
		}
	}
	for(int i=1;i<=n;++i) 
		if(!a[i]) printf("S");
		else printf("W");
	puts("");
	return true;
}
int main(){
	scanf("%d%s",&n,str+1);
	a[1]=0;a[2]=0;
	if(check()) return 0;
	a[1]=0;a[2]=1;
	if(check()) return 0;
	a[1]=1;a[2]=0;
	if(check()) return 0;
	a[1]=1;a[2]=1;
	if(check()) return 0;
	puts("-1");
	return 0;
}