#include<cstdio>
int I,O,T,J,L,S,Z,x;
int main(){
	scanf("%d%d%d%d%d%d%d",&I,&O,&T,&J,&L,&S,&Z);
	x=(I%2+J%2+L%2)%3;
	if(I&&J&&L&&x==2) x=1;
	printf("%lld\n",1ll*I+J+L+O-x);
}