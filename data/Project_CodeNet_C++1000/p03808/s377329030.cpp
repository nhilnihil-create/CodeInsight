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
long a[100005];
long sum;
long s;
long d[100005];

int main(){
	scanf("%ld", &n);
	for(int i = 0; i < n; i++){
		scanf("%ld", &a[i]);
		sum += a[i];
	}
	
	for(int i = 0; i < n; i++){
		d[i] = a[(i+1)%n] - a[i];
	}
	
	if(sum % (n*(n+1)/2) != 0){
		//printf("case 1\n");
		printf("NO\n");
		return 0;
	}
	s = sum / (n*(n+1)/2);
	for(int i = 0; i < n; i++){
		if(s - d[i] < 0 || (s-d[i]) % n != 0){
			//printf("case 2 %d\n", i);
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}
