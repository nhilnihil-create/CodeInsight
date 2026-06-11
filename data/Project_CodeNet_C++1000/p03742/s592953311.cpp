#include<bits/stdc++.h>
using namespace std;
#define R register int
#define LL long long

LL x, y;
void work()
{
	scanf("%lld%lld", &x, &y);
	if(abs(x - y) <= 1) printf("Brown\n");
	else printf("Alice\n"); 
}

int main()
{
	//freopen("in.in", "r", stdin);
	work();
	//fclose(stdin);
	return 0;
}