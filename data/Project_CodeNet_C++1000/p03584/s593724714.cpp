#include<stdio.h>
typedef long long ll;
void fmax(ll&a,ll b){
	a<b?a=b:0;
}
int a[100010],b[100010],n;
ll get(int x){
	int i;
	ll s=0;
	for(i=1;i<=n;i++){
		if((x&a[i])==a[i])s+=b[i];
	}
	return s;
}
int main(){
	int k,i,x;
	ll s;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)scanf("%d%d",a+i,b+i);
	s=get(k);
	x=k;
	for(i=0;i<30;i++){
		if(k>>i&1)fmax(s,get(x&~(1<<i)));
		x|=1<<i;
	}
	printf("%lld",s);
}