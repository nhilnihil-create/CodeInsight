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

typedef unsigned long long LL;

LL N;
vector<LL> D;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	LL A, B, C;
	cin >> A >> B >> C;

	if( (A % 2) == 0 || (B % 2) == 0 || (C % 2) == 0){
		printf("0\n");
	}
	else{
		LL ans = min(A*B, min(B*C, C*A));
		printf("%lld\n", ans);
	}
	return 0;
}