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

	int N;
	long long ans = 0;
	
	cin >> N;
	for(int i=1; i<=N; i++){
		ans += (long long) i;
	}
	
	printf("%lld\n", ans);
	return 0;
}