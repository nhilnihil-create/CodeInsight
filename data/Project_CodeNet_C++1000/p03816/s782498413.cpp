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
using Graph = vector<vector<int>>;

static long long INF = (1LL<<62);

int N;
map<long long, int> M;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for(int i=0; i<N; i++){
		long long a;
		cin >> a;
		if(M.count(a) == 0){
			M[a] = 1;
		}
		else{
			M[a]++;
		}
	}

	int c1 = 0, c2 = 0;
	for(auto itr = M.begin(); itr != M.end(); itr++){
		long long k = itr->first;
		int v = itr->second;
		if(v >= 3){
			if((v % 2) == 0){
				M[k] = 2;
			}
			else{
				M[k] = 1;
			}
		}
		if(M[k] == 1){
			c1++;
		}
		else if(M[k] == 2){
			c2++;
		}
	}
	int ans = 0;
	if((c2 % 2) == 0){
		ans = c1 + c2;
	}
	else{
		ans = c1 - 1 + c2;
	}

	printf("%d\n", ans);
	return 0;
}

