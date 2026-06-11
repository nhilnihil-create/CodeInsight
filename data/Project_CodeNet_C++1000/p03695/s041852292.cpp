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


int getKey(int r) {
	if(r <= 0) return 0;
	else if(r >= 1    && r <=  399) return 1;
	else if(r >= 400  && r <=  799) return 2;
	else if(r >= 800  && r <= 1199) return 3;
	else if(r >= 1200 && r <= 1599) return 4;
	else if(r >= 1600 && r <= 1999) return 5;
	else if(r >= 2000 && r <= 2399) return 6;
	else if(r >= 2400 && r <= 2799) return 7;
	else if(r >= 2800 && r <= 3199) return 8;
	else return 9;
}

int main(int argc, char* argv[]){
	int N;
	map<int, int> mp;

	cin >> N;

	int f = 0;
	for(int i=1; i<=N; i++){
		int r, k;
		cin >> r;
		k = getKey(r);
		if(k == 9){
			f++;
			continue;
		}
		if(mp.count(k)==0){
			mp[k] = 1;
		}
	}

	int m = mp.size();
	if(f == 0){
		printf("%d %d\n", m, m);
	}
	else if(m == 0){
		printf("%d %d\n", 1, f);
	}
	else{
		printf("%d %d\n", m, m+f);
	}
	return 0;
}