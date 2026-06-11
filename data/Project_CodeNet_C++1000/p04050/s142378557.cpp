#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
#define M 120
using namespace std;
namespace IO{
	const int BS=(1<<20)+5; int Top=0;
	char Buffer[BS],OT[BS],*OS=OT,*HD,*TL,SS[20]; const char *fin=OT+BS-1;
	char Getchar(){if(HD==TL){TL=(HD=Buffer)+fread(Buffer,1,BS,stdin);} return (HD==TL)?EOF:*HD++;}
	void flush(){fwrite(OT,1,OS-OT,stdout);}
	void Putchar(char c){*OS++ =c;if(OS==fin)flush(),OS=OT;}
	void write(int x){
		if(!x){Putchar('0');return;} if(x<0) x=-x,Putchar('-');
		while(x) SS[++Top]=x%10,x/=10;
		while(Top) Putchar(SS[Top]+'0'),--Top;
	}
	int read(){
		int nm=0,fh=1; char cw=Getchar();
		for(;!isdigit(cw);cw=Getchar()) if(cw=='-') fh=-fh;
		for(;isdigit(cw);cw=Getchar()) nm=nm*10+(cw-'0');
		return nm*fh;
	}
}
using namespace IO;
int n,m,p[M],tg,ct,tot,t[M];
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;i++) p[i]=read(),ct+=(p[i]&1);
	if(ct>2){puts("Impossible");return 0;}
	for(int i=2;i<=m;i++){
		if(!(p[i]&1)) continue;
		if(!(p[1]&1)) swap(p[1],p[i]);
		else swap(p[m],p[i]);
	}
	if(n==1){puts("1\n1\n1");return 0;}
	if(m==1){printf("%d\n2\n%d %d\n",p[1],1,p[1]-1);return 0;}
//	for(int i=1;i<=m;i++)  printf("I = %d   p[i] = %d\n",i,p[i]); 
	if(p[1]>1) t[tot=1]=p[1]-1;
	for(int i=2;i<=m;i++) t[++tot]=p[i]; t[tot]++;
	for(int i=1;i<=m;i++) printf("%d%c",p[i],i<m?' ':'\n');
	printf("%d\n",tot);
	for(int i=1;i<=tot;i++) printf("%d%c",t[i],i<tot?' ':'\n');
	return 0;
}