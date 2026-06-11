#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int a, b;
	scanf("%lld%lld", &a, &b);
	if(llabs(a-b) <= 1)printf("Brown\n");
	else printf("Alice\n");
	return 0;
}
