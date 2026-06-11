#include <iostream>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
typedef long long lint;
const int N=1e5+5;
int n,len,q,pos[N];
//int cnt_0,cnt_1,buk_0[N],buk_1[N];
bool stat[N];//0: clockwise, 1: counter

inline int nxi(){
	int x=0;
	char c;
	while((c=getchar())>'9'||c<'0');
	while(x=x*10-48+c,(c=getchar())>='0'&&c<='9');
	return x;
}

int main(){
#ifndef ONLINE_JUDGE
	//freopen("d.in","r",stdin);
#endif
	n=nxi(),len=nxi(),q=nxi();
	for(int i=1; i<=n; ++i){
		pos[i]=nxi(),stat[i]=nxi()-1;
	}
	int cyc=q/len,rest=q-cyc*len;
	lint dlt=0;
	for(int i=1; i<=n; ++i){
		if(stat[i]==0){
			dlt+=cyc;
			int tgt=pos[i]+rest;
			if(tgt>=len) ++dlt,tgt-=len;
			pos[i]=tgt;
		}
		else{
			dlt-=cyc;
			int tgt=pos[i]-rest;
			if(tgt<0) --dlt,tgt+=len;
			pos[i]=tgt;
		}
	}
	std::sort(pos+1,pos+n+1);
	dlt%=n;
	if(dlt<0) dlt+=n;
	for(int i=dlt+1; i<=n; ++i){
		printf("%d\n",pos[i]);
	}
	for(int i=1; i<=dlt; ++i){
		printf("%d\n",pos[i]);
	}
	return 0;
}