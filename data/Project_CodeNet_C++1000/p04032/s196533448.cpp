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

int T[26][100002] = {0};
static char C[27] = "abcdefghijklmnopqrstuvwxyz";

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	string S;
	cin >> S;
	for(int i=0; i<26; i++){
		char c = C[i];
		for(int j=0; j<S.size(); j++){
			if(c == S[j]){
				T[i][j] = 1;
			}
			else{
				T[i][j] = 0;
			}
		}
	}

	int found = 0;
	int s, e;
	
	for(int i=0; i<26; i++){
		s = -1;
		e = -1;
		for(int j=0; j<S.size(); j++){
			if(T[i][j] == 0){
				continue;
			}
			e = j;
			if(s == -1){
				s = j;
				continue;
			}
			else{
				if(e - s + 1 < 4){
					found = 1;
					break;
				}
				s = e;
			}
		}
		if(found == 1){
			break;
		}
	}
	if(found == 0){
		printf("-1 -1\n");
	}
	else{
		printf("%d %d\n", s+1, e+1);
	}
	return 0;
}