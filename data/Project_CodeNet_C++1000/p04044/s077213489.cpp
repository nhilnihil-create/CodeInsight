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

	int N, L;
	vector<string> S;

	cin >> N >> L;
	for(int i=0; i<N; i++){
		string s;
		cin >> s;
		S.push_back(s);
	}
	sort(S.begin(), S.end());
	for(int i=0; i<N; i++){
		printf("%s", S[i].c_str());
	}
	printf("\n");
	return 0;
}