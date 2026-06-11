#include <stdio.h>
#include <string.h>
#define R register
#define int long long
inline char getalpha(){R char c;for (;(c=getchar())<'A'||c>'Z';);return c;}
inline bool query(int x){
	printf("? %lld\n",x);
	fflush(stdout);
	return getalpha()=='Y';
}
#define MN 10
int len,b10[MN]={1},ans;
main(){
	for (R int i=1; i<=9; ++i) b10[i]=b10[i-1]*10;	
	for (len=1; len<=9; ++len)
		if (query(b10[len]-1)&&!query(b10[len])) break;
	if (len==10){
		for (len=0; len<9; ++len)
			if (query(b10[len+1]-1)) break;
		printf("! %lld\n",b10[len]);
		fflush(stdout);return 0;
	}
	for (R int i=1; i<=len; ++i){
		R int l=i==1,r=9,m;
		while(l<r){
			m=l+r>>1;if (query((ans+m*b10[len-i])*10+b10[len-i+1]-1)) r=m;
			else l=m+1;
		}ans+=l*b10[len-i];
	}printf("! %lld\n",ans);fflush(stdout);return 0;
}