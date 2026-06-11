#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

const int MaxN = 505;
int a[MaxN*MaxN], x[MaxN*MaxN];

int main(){
	int n; scanf("%d",&n);
	for(int i=1; i<=n; ++i){
		int r; scanf("%d",&r);
		x[r] = i; // 直接存
	}
	bool ok = true;
	for(int i=1; i<=n*n; ++i){
		if(x[i] == 0) continue;
		int cnt = a[i] = x[i];
		for(int j=1; j<i&&cnt>1; ++j)
			if(a[j] == 0)
				a[j] = x[i], -- cnt;
		if(cnt > 1) ok = false;
	}
	for(int i=n*n; i>=1; --i){
		if(x[i] == 0) continue;
		int cnt = n-x[i];
		for(int j=n*n; j>i&&cnt>0; --j)
			if(a[j] == 0)
				a[j] = x[i], -- cnt;
		if(cnt > 0) ok = false;
	}
	if(ok){
		printf("Yes\n");
		for(int i=1; i<=n*n; ++i)
			printf("%d ",a[i]);
	}
	else printf("No\n");
	return 0;
}