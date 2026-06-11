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

int N, M;
vector<vector<int>> G;

//差分取って<=0のポイントで区切る。
int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	G.resize(N);
	for(int i=0; i<N; i++){
		G[i].clear();
	}
	for(int i=0; i<M; i++){
		int a, b;
		cin >> a >> b;
		G[a-1].push_back(b-1);
		G[b-1].push_back(a-1);
	}


	int possible = 0;
	for(auto nv : G[0]){
		for(auto nnv : G[nv]){
			if(nnv == N-1){
				 possible = 1;
				 break;
			}
		}
		if(possible == 1){
			break;
		}
	}
	if(possible == 1){
		printf("POSSIBLE\n");
	}
	else{
		printf("IMPOSSIBLE\n");
	}
	return 0;
}
