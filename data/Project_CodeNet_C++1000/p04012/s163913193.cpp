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

	string w;
	cin >> w;
	map<char, int> M;

	for(int i=0; i<w.size(); i++){
		char c = w[i];
		if(M.count(c) == 0){
			M[c] = 1;
		}
		else{
			M[c]++;
		}
	}
	int ans = 0;
	for(auto itr = M.begin(); itr != M.end(); itr++){
		char c = itr->first;
		int  v = itr->second;
		if((v % 2) != 0){
			ans = 1;
			break;
		}
	}
	if(ans==1){
		printf("No\n");
	}
	else{
		printf("Yes\n");
	}
	return 0;
}
