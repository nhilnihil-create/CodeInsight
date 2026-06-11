#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
int a[100010],n,l;
int main(){
	int pos=0;
	scanf("%d%d",&n,&l);
	for (int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		if (a[i]+a[i-1]>=l) pos=i;
	}
	if (!pos) printf("Impossible\n");
	else{
		printf("Possible\n");
		for(int i=n-1;i>=pos;i--)
            printf("%d\n",i);
		for(int i=1;i<pos;i++)
            printf("%d\n",i);
	}
	return 0;
}