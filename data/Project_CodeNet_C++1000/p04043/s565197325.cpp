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

	map<int, int> M;
	for(int i=0; i<3; i++){
		int v;
		cin >> v;
		if(M.count(v) == 0){
			M[v] = 1;
		}
		else{
			M[v]++;
		}
	}
	if(M[5]==2 && M[7]==1){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
	return 0;
}