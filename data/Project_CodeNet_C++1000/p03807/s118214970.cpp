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
long long INF = (1LL<<62);
typedef long long LL;

LL func(string s){
	LL ret = 0;
	for(int i=1; i<s.size(); i++){
		if(s[i-1] == s[i]){
			ret++;
			i++;
		}
	}
	return ret;
}

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	LL N;
	vector<LL> A;
	LL even=0, odd=0;

	cin >> N;
	for(int i=0; i<N; i++){
		LL a;
		cin >> a;
		A.push_back(a);
		if((a % 2) == 0){
			even++;
		}
		else{
			odd++;
		}
	}

	if((odd % 2) == 0){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
	return 0;
}