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

	int K, S;
	cin >> K >> S;

	int x, y;

	long long ans = 0;
	for(x = 0; x<=K; x++){
		for(y = 0; y<=K; y++){
			int z = S - x - y;
			if(z >=0 && z <= K){
				ans++;
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}