#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1e5+10;
int n,a[MAXN];
int main (){
	scanf("%d",&n);
	for(int i = 1;i <= n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1,greater<int>());
	for(int i = 1;i <= n;i++){
		if(i+1 > a[i+1]){
			int j = 0;
			for(;a[i+1+j] == i;j++);
			if((j&1)||(a[i]-i)&1) printf("First");
			else printf("Second");
			break;
		}
	}
	return 0;
}