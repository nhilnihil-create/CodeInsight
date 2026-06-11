#include<cstdio>
long long x,y;
int main() {
	scanf("%lld %lld",&x,&y);
	if(x-y>1||y-x>1)
		printf("Alice\n");
	else printf("Brown\n");
	return 0;
}