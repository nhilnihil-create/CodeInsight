#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int Mod=1e9+7;
int f[1000010];
int tot=0;
int mult(int x,int y){
	return(int)((long long)x*(long long)y%(long long)Mod);
}
int main(){
	int n;
	scanf("%d",&n);
	f[1]=n;f[2]=mult(n,n);
	for (int i=3;i<=n;++i){
		f[i]=((f[i-1]+mult(n-1,n-1))%Mod+Mod)%Mod;
		f[i]=((f[i]+n-i+2)%Mod+Mod)%Mod;
		if (i>3) f[i]=((f[i]+tot)%Mod+Mod)%Mod; 
		if (i>=3) tot=((tot+f[i-2])%Mod+Mod)%Mod;
	}
	printf("%d\n",f[n]);
	return 0;
}