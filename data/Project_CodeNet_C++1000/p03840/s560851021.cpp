#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long int i,o,t,j,l,s,z;
int main(){
//	freopen("a.in","r",stdin);
	scanf("%lld%lld%lld%lld%lld%lld%lld",&i,&o,&t,&j,&l,&s,&z);
	if(i==0||j==0||l==0){
		printf("%lld",(i/2)*2+j/2*2+l/2*2+o);
	}else{
		printf("%lld",max(3+((i-1)/2)*2+(j-1)/2*2+(l-1)/2*2+o,(i/2)*2+j/2*2+l/2*2+o));
	}
	return 0;
}