#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	ll I=gi(),O=gi(),T=gi(),J=gi(),L=gi(),S=gi(),Z=gi();
	//T,S,Z都没用，O直接计入答案
	//然后只有 II JJ LL JLI 三种拼法
	ll o=std::max(0ll,std::min(std::min(J,L),I)-1);
	I-=o,J-=o,L-=o;
	o=3*o+O;
	if(I)o+=(I-1)/2*2,I-=(I-1)/2*2;
	if(J)o+=(J-1)/2*2,J-=(J-1)/2*2;
	if(L)o+=(L-1)/2*2,L-=(L-1)/2*2;
	if(I&&J&&L){
		o+=3;int r=(I==2)+(J==2)+(L==2);
		if(r==2)++o;
		else if(r==3)o+=3;
	}else o+=I/2*2+J/2*2+L/2*2;
	printf("%lld\n",o);
	return 0;
}
