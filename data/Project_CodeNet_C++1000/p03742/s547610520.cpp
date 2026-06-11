#include<cstdio>
#include<algorithm>
using namespace std;

long long Abs(long long x) {
	if(x<0)return -x;
	else return x;
}

int main() {
	#ifdef LOACL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	long long x,y;
	scanf("%lld %lld\n",&x,&y);
	puts(Abs(x-y)>=2?"Alice":"Brown");
	return 0;
}