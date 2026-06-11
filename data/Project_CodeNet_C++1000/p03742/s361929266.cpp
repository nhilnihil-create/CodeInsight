#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <math.h>
using namespace std;

typedef long long ll;
ll X, Y;

int main() {
	scanf("%lld%lld", &X, &Y);
	puts(abs(X - Y) > 1 ? "Alice" : "Brown");
	return 0;
}