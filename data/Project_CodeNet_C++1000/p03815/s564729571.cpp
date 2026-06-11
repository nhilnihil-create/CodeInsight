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

	long long x;
	cin >> x;

	long long q = x / 11;
	long long r = x % 11;

	long long ans = 0;
	ans = q * 2;
	if(r > 0 && r <= 6){
		ans = ans + 1;
	}
	else if(r > 6){
		ans = ans + 2;
	}
	printf("%lld\n", ans);
	return 0;
}