#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;

const int N=100005;

int n;
bool ans;
int a[N];

int main(){
	int i,j;
	scanf("%d",&n);
	for (i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	reverse(a+1,a+1+n);
	for (i=1;i<=n;i++)
		if (i+1>a[i+1]){
			for (j=i+1;a[j]==i;j++) ans^=1;
			ans|=(a[i]-i)&1;
			if (ans) printf("First\n");
			else printf("Second\n");
			return 0;
		} 
	return 0;
} 