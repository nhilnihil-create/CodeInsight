#include<cstdio>
using namespace std;
using ll = long long;
const static int MOD = 1000000007;

int main(){
	ll X, Y;
	scanf("%lld %lld", &X, &Y);
	if(X - Y >= -1 && Y - X >= -1) printf("Brown\n");
	else printf("Alice\n");
	return 0;
}