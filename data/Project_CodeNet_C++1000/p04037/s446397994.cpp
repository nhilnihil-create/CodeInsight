#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize(Ofast)
#pragma GCC optimize("inline")
#include<bits/stdc++.h>
#define getchar gc
using namespace std;
const int L=1000000;
char LZH[L],*SSS,*TTT;
inline char gc(){if (SSS==TTT) TTT=(SSS=LZH)+fread(LZH,1,L,stdin);return *SSS++;}
inline int read(){
	int res=0,pd=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')pd=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){res=res*10+ch-'0';ch=getchar();}
	return res*pd;
}
int a[100003];
inline bool cmp(int x,int y){return x>y;}
inline void Yes(){puts("First");}
inline void No(){puts("Second");}
signed main(){
	int n=read();
	for (int i=1;i<=n;++i) a[i]=read();
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;++i) if (i+1>a[i+1]){
		if ((a[i]-i)%2) Yes();
		else{
			int now=i+1,flag=0;
			while(a[now]==i) flag^=1,now++;
			if (flag) Yes();else No();
		}
		return 0;
	}
	return 0;
} 