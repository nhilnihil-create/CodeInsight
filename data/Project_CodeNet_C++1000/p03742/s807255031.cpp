//#include "debug.h"
#include <string.h>
#include <limits.h>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 100000

long x, y;

int input() {
	if (scanf("%ld %ld", &x, &y) < 0) return 0;
	return 1;
}

void init() {
}

long solve() {
	return abs(x-y)>1;
}

void output(long ans) {
	printf("%s\n", ans? "Alice": "Brown");
}

void cleanup() {
}

int main() {
	while (input()) {
		init();
		output(solve());
		cleanup();
		//break;
	}
}



