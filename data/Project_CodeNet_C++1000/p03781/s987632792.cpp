#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<cstring>

using namespace std;

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int x,n;
	scanf("%d",&x);
	n=(int)sqrt(x*2.0);
	if(n*(n+1)/2==x){
		printf("%d\n",n);
	}
	else{
		if(n*(n+1)/2<x)printf("%d\n",n+1);
		else printf("%d\n",n);
	}
	return 0;
}

