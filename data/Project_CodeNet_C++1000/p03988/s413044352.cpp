#include<bits/stdc++.h>
using namespace std;
const int N=1006;
int n,m,t,a[N];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&t),++a[t],m=max(m,t);
	for(int i=m/2+1;i<=m;++i) if(a[i]<2){printf("Impossible"); return 0;}
	if(m%2==0){if(a[m/2]!=1){printf("Impossible"); return 0;}a[m/2]=0;}
	else{if(a[m/2+1]!=2){printf("Impossible"); return 0;}}
	for(int i=1;i<=m/2;++i) if(a[i]){printf("Impossible"); return 0;}
    printf("Possible");
	return 0;
}