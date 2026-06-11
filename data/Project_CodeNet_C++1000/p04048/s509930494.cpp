#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
ll f(ll A,ll B){
	if(A>B)std::swap(A,B);
	if(B%A==0)return A*(B/A*2-1);
	else return 2*A*(B/A)+f(A,B%A);
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	ll N=gi(),X=gi();
	printf("%lld\n",N+f(X,N-X));
	return 0;
}
