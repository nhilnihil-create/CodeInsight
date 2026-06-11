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

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	LL N, A, B;
	cin >> N >> A >> B;

	LL mi = A*(N-1) + B;
	LL ma = B*(N-1) + A;
	LL ans = ma - mi + 1;
	printf("%lld\n", max(ans, 0LL));
	return 0;
}