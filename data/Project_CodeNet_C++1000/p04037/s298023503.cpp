/*
by.YXH_XianYu
 */
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define MXN 100003

int n,
	a[MXN];
bool naive;

bool comp(int a, int b){
	return a>b;
}

int main(){

	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	std::sort(a+1,a+n+1,comp);
	
	int i,j;
	for(i=1;i<=n;i++)
		if(a[i]<i)
			break;
	i--;
	for(j=i;j<=n;j++)
		if(i>a[j])
			break;
	j--;
	//printf("i=%d a[i]=%d j=%d\n",i,a[i],j);
	if(((j-i)&1) || ((a[i]-i)&1))
		printf("First\n");
	else
		printf("Second\n");

	//system("pause");
	return 0;
}
