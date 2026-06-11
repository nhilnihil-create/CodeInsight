#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <bitset>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <chrono>
#include <random>
#include <tuple>
#include <utility>

const int INF = 1000000009;
const long LINF = 1123456789012345678;

long n;
long a, b, c, d;
long dif;

int main(){
	scanf("%ld %ld %ld %ld %ld", &n, &a, &b, &c, &d);
	dif = b - a;
	for(int x = 0, y = 1-n; x < n; x++, y++){
		long min = std::min(x*c + y*d, y*c + x*d);
		long max = std::max(x*c + y*d, y*c + x*d);
		if(min <= dif && dif <= max){
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}
