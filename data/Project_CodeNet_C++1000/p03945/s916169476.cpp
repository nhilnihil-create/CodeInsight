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

	string S;
	cin >> S;

	int ans = 0;
	for(int i=0; i<S.size(); i++){
		if(i<S.size() - 1 && S[i+1] != S[i]){
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}