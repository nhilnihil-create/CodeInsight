#include<bits/stdc++.h>
#define il inline
#define vd void
typedef long long ll;
il ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),m=gi(),k=gi();
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if((((i-j+m)/k)&1)==0&&(((i+j)/k)&1)==0)putchar('R');
			if((((i-j+m)/k)&1)==0&&(((i+j)/k)&1)==1)putchar('Y');
			if((((i-j+m)/k)&1)==1&&(((i+j)/k)&1)==0)putchar('G');
			if((((i-j+m)/k)&1)==1&&(((i+j)/k)&1)==1)putchar('B');
		}
		puts("");
	}
	return 0;
}
