#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <set>

using namespace std;

typedef long long ll;

const int maxn= 1e5+5;

int main() {
	int n , maxnum = 0 , a[maxn] = {0};
	scanf("%d",&n);
	while(n--) {
		int now;
		scanf("%d",&now);
		a[now]++;
		a[now-1]++;
		a[now+1]++;
	}
	for(int i=0 ; i<maxn ; i++) {
		if(a[i] > maxnum) maxnum = a[i];
	}
	printf("%d\n",maxnum);
	return 0;
}