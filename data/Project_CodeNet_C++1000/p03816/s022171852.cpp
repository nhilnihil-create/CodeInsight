#include<bits/stdc++.h>//万能头文件可好 
using namespace std;
#define ll long long
bool a[100005];
int main(){//主函数 
	ll n,k,i,again=0;
	scanf("%lld",&n);
	for(i=1;i<=n;i++){
		scanf("%lld",&k);
		if(a[k])again++;
		else a[k]=true;
	}
	again+=again%2;
	printf("%lld",n-again);
	return 0;//over~
}