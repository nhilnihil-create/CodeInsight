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

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	long long a, b, x;
	cin >> a >> b >> x;

	if(x == 1){
		printf("%lld\n", b - (a - 1));
		return 0;
	}

	long long ans = 0;
	long long r = (a % x);
	if(r == 0){
		ans = (b - a) / x;
		ans += 1;
	}
	else{
		long long u = a + (x - r);
		if(u > b){
			ans = 0;
		}
		else{
			ans = (b - u) / x;
			ans += 1;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
