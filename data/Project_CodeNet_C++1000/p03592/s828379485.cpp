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

int P[1000004] = {0};

string S, T;
int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N, M, K;
	cin >> N >> M >> K;

	for(int i=0; i<=N; i++){
		for(int j=0; j<=M; j++){
			int c = i*j + (N-i)*(M-j);
			P[c] = 1;
		}
	}
	P[0] = 1;
	if(P[K] == 1){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
	return 0;
}

