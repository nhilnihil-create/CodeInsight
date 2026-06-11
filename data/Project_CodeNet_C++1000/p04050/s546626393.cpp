#include <cmath>
#include <cstdio>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
//Constant
const int M=100;
//Quick Read
int Read(){
	int x=0;
	bool neg=false;
	char c=getchar();
	while(isdigit(c)==false)neg^=c=='-',c=getchar();
	while(isdigit(c)==true)x=x*10+c-'0',c=getchar();
	return neg==true?-x:x;
}
inline void Read(int &x){x=Read();}
//Main
int a[M+1],b[M+1],odd[M+1];
int main(){
	// freopen("AGC001D.in","r",stdin);
	// freopen("AGC001D.out","w",stdout);
	int n=Read(),m=Read(),num=0;
	for(int i=1;i<=m;++i){
		Read(a[i]);
		if(a[i]%2==1)odd[++num]=i;
	}
	if(m==1){
		printf("%d\n",a[1]);
		if(a[1]==1)printf("%d\n%d\n",1,1);
		else printf("%d\n%d %d\n",2,1,a[1]-1);
		return 0;
	}
	if(num>2){
		printf("Impossible\n");
		return 0;
	}
	std::sort(odd+1,odd+num+1);
	if(num>=1)std::swap(a[odd[1]],a[m]);
	if(num>=2)std::swap(a[odd[2]],a[1]);
	for(int i=1;i<=m;++i)printf("%d%c",a[i]," \n"[i==m]);
	for(int i=1;i<=m;++i)b[i]=a[i];
	++b[1],--b[m];
	if(b[m]==0)--m;
	printf("%d\n",m);
	for(int i=1;i<=m;++i)printf("%d%c",b[i]," \n"[i==m]);
	return 0;
}
