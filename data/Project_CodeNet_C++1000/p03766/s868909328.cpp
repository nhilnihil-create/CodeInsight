#include<cstdio>
#define MOD 1000000007
#define f(i,n) for(long long i=0;i<(long long)(n);i++)


int main(){
long long a,b,c,x,n;
scanf("%lld",&n);
a=1;
b=n;
c=n*n;
c=c%MOD;
if(n==1){
printf("1\n");
return 0;
}
f(i,n-2){
x=(2*c)-b+a-1;
x=(x+MOD)%MOD;
a=b;
b=c;
c=x;
}
printf("%lld\n",c);
return 0;
}