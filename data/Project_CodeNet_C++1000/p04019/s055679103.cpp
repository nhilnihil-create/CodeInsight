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

typedef unsigned long long LL;

LL N;
vector<LL> D;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	string S;
	cin >> S;
	LL n=0, w=0, s=0, e=0;
	for(int i=0; i<S.size(); i++){
		if(S[i] == 'N'){ n++; }
		if(S[i] == 'W'){ w++; }
		if(S[i] == 'S'){ s++; }
		if(S[i] == 'E'){ e++; }
	}
	if(n == 0 && s != 0){
		printf("No\n");
		return 0;
	}
	else if(n != 0 && s == 0){
		printf("No\n");
		return 0;
	}
	else if(w == 0 && e != 0){
		printf("No\n");
		return 0;
	}
	else if(w != 0 && e == 0){
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	return 0;
}