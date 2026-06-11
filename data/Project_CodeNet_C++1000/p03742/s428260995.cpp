#include <cstdio>
#define abs(x) ((x) < 0 ? -(x) : (x))
using namespace std;

long long x, y;

int main()
{
	scanf("%lld%lld", &x, &y);
	if(abs(x - y) < 2){
		printf("Brown\n");
	}
	else{
		printf("Alice\n");
	}
}