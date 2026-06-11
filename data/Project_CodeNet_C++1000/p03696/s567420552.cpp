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
string S;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	cin >> S;

	string s;
	for(int i=0; i<S.size(); i++){
		if(S[i] == '('){
			s.push_back(S[i]);
		}
		else{
			if(s[s.size()-1] == '('){
				s.pop_back();
			}
			else{
				s.push_back(S[i]);
			}
		}
	}
	if(s[0] == '('){
		printf("%s", S.c_str());
		for(int i=0; i<s.size(); i++){
			printf(")");
		}
		printf("\n");
		return 0;
	}
	else{
		int c1 = 0, c2 = 0;
		for(int i=0; i<s.size(); i++){
			if(s[i] == ')'){
				c1++;
			}
			else{
				c2++;
			}
		}
		for(int i=0; i<c1; i++){
			printf("(");
		}
		printf("%s", S.c_str());
		for(int i=0; i<c2; i++){
			printf(")");
		}
		printf("\n");
		return 0;
	}
	return 0;
}