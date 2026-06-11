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

#define int long

const int INF = 1000000009;
const long LINF = 1123456789012345678;

int n, a, b;
int h[100005];
int h1[100005];

int ok = INF;
int ng = 0;

long divCeil(long num1, long num2){
	return (num1+num2-1)/num2;
}

bool check(int in){
	int cnt = 0;
	for(int i = 0; i < n; i++){
		cnt += divCeil(std::max(0L, h[i] - b*in), a-b);
	}
	if(cnt > in){
		return false;
	}else{
		return true;
	}
}
	
signed main(){
	scanf("%ld %ld %ld", &n, &a, &b);
	for(int i = 0; i < n; i++){
		scanf("%ld", &h[i]);
	}
	while(std::abs(ok-ng) > 1){
		int mid = (ok + ng) / 2;
		if(check(mid)){
			ok = mid;
		}else{
			ng = mid;
		}
		//printf("%ld %ld\n", ng, ok);
	}
	printf("%ld\n", ok);
	return 0;
}
