#include <bits/stdc++.h>

using namespace std;

long long n;

int main(){
	scanf("%lld",&n);
	int l = 1,r = n,re = n;
	while(l <= r){
		int mid = l + r >> 1;
		if(1LL * mid * (mid + 1) / 2 >= n)
			re = mid,r = mid - 1;
		else l = mid + 1;
	}
	printf("%d\n",re);
	return 0;
}
