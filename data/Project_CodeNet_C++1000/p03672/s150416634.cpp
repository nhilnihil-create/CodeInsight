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

int isEvenStr(string s){
	int ret = 1;
	int L = s.size();
	if((L % 2) != 0){
		return 0;
	}


	for(int i=0; i<L/2; i++){
		if(s[i] != s[(L/2)+i]){
			ret = 0;
			break;
		}
	}
	return ret;
}

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	string S;
	cin >> S;

	while(true){
		S.pop_back();
		int r =isEvenStr(S);
		if(r == 1){
			break;
		}
	}
	printf("%d\n", (int)S.size());
	return 0;
}