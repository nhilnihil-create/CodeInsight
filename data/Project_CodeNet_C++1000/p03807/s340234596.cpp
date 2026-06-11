#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n;
int cnt0,cnt1;
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		if(read()&1)++cnt1;
		else ++cnt0;
	}
	while(cnt1>1)++cnt0,cnt1-=2;
	puts(cnt1&&cnt0?"NO":"YES");
	return 0;
}
