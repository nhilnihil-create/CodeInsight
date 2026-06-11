#include <bits/stdc++.h>
using namespace std;

long long _abs(long long a) {
	return a<0 ? -a : a;
}
int main() {
	long long x,y;
	scanf("%lld%lld",&x,&y);
	if(_abs(x-y)<=1) puts("Brown");
	else puts("Alice");
	return 0;
}
