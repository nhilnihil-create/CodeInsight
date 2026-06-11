/*
  mail: mleautomaton@foxmail.com
  author: MLEAutoMaton
  This Code is made by MLEAutoMaton
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<set>
#include<map>
#include<iostream>
using namespace std;
#define ll long long
#define REP(a,b,c) for(int a=b;a<=c;a++)
#define re register
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
inline int gi(){
	int f=1,sum=0;char ch=getchar();
	while(ch>'9' || ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){sum=(sum<<3)+(sum<<1)+ch-'0';ch=getchar();}
	return f*sum;
}
const int N=200010,Mod=1e9+7;
int fac[N],fai[N],inv[N],h,w,a,b;
void init(){
	fac[0]=fai[0]=inv[0]=inv[1]=1;
	for(int i=1;i<=200000;i++)fac[i]=1ll*fac[i-1]*i%Mod;
	for(int i=2;i<=200000;i++)inv[i]=1ll*(Mod-Mod/i)*inv[Mod%i]%Mod;
	for(int i=1;i<=200000;i++)fai[i]=1ll*fai[i-1]*inv[i]%Mod;
}
int C(int n,int m){if(n<m || m<0 || n<0)return 0;return 1ll*fac[n]*fai[m]%Mod*fai[n-m]%Mod;}
int num(int a,int b){return C(a+b,a);}
int main(){
	init();
	h=gi();w=gi();a=gi();b=gi();int ans=0;
	for(int i=1;i<=h-a;i++){
		//(1,1)->(i,b)   (i,b+1)->(h,w)
		ans=(ans+1ll*num(i-1,b-1)*num(h-i,w-b-1)%Mod)%Mod;
//		printf("%d %d\n",num(i-1,b-1),num(h-i,w-b-1));
	}
	printf("%d\n",ans);
	return 0;
}
