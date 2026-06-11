#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

int a, b, c, d, e, f, g;
ll sol = 0;

int main(){
	scanf("%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g);
	if((d % 2 + e % 2 + a % 2) > 1 && d && e && a){
		d--; e--; a--;
		sol += 6LL;
	}
	sol += 2LL * b; b = 0;
	sol += 4LL * (e / 2LL);	
	sol += 4LL * (d / 2LL);
	d %= 2LL; e %= 2LL;
	sol += 4LL * (a / 2LL); a %= 2LL; 
	printf("%lld\n", sol / 2LL);
}