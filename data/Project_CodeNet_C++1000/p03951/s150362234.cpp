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

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	LL N;
	string s, t;
	cin >> N;
	cin >> s;
	cin >> t;

	int w = 0;
	for(w=0; w<N; w++){
		int match = 1;
		for(int i=0; i<t.size() - w; i++){
			if(s[w+i] != t[i]){
				match = 0;
				break;
			}
		}
		if(match == 1){
			break;
		}
	}
	printf("%lld\n", N+w);
	return 0;
}