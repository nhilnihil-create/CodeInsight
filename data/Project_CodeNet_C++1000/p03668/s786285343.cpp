#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
#define M 200020
using namespace std;
namespace IO{
	const int BS=(1<<20); int Top=0;
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
int n,fs[M],nt[M],to[M],tmp;
void link(int x,int y){nt[tmp]=fs[x],fs[x]=tmp,to[tmp++]=y;}
int DP(int x,int last){
	int sg=0;
	for(int i=fs[x];i!=-1;i=nt[i]) if(to[i]!=last) sg^=(DP(to[i],x)+1);
	return sg;
}
int main(){
	n=read(),memset(fs,-1,sizeof(fs));
	for(int i=1;i<n;i++){int x=read(),y=read();link(x,y),link(y,x);}
	puts(DP(1,0)?"Alice":"Bob"); return 0;
}