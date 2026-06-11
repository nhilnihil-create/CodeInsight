#include<cstdio>
long long q,w,e,r,t,y,u;
int main(){
	scanf("%lld%lld%lld%lld%lld%lld%lld",&q,&w,&e,&r,&t,&y,&u);
	if((q%2+r%2+t%2)%3==0) printf("%lld",q+w+r+t);
	else if(q>0&&r>0&&t>0||(q%2+r%2+t%2)%3==1) printf("%lld",q+w+r+t-1);
	else printf("%lld",q+w+r+t-2);
	return 0;
}