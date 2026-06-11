#include<cstdio>
#include <algorithm>
#include <iostream>
#include <functional>
#include<cmath>
#include<string.h>
#include<vector>

#define mod 1000000007

int main(){
	int n;
	long long ans;
	char a[100],b[100];
	
	scanf("%d",&n);
	scanf("%s",a);
	scanf("%s",b);
	
	if(a[0] == b[0])ans=3;
	else ans=6;
	for(int i=1;i<n;i++){
		if(a[i-1]==b[i-1])ans=(ans*2)%mod;
		else if(!(a[i-1]==a[i]||b[i-1]==b[i]||a[i]==b[i])) ans=(ans*3)%mod;
	}
	
	printf("%I64d\n",ans);
		
	
	return 0;
}