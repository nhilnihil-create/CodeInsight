#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>

#include <bits/stdc++.h>
#include <cmath>
#include <limits>

using namespace std;
typedef long long LL;
static long long INF = (1LL<<62);

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	LL N;
	LL min = INF;

	cin >> N;
	LL ans = 0;
	for(int i=0; i<N; i++){
		LL a, b;
		cin >> a >> b;
		if(b < min){
			min = b;
			ans = a;
		}
	}
	ans += min;
	printf("%lld\n", ans);
	return 0;
}