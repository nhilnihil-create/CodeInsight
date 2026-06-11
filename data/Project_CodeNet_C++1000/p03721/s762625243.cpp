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

map<int, int> mp;

int main(int argc, char* argv[]){
	long long N, K;
	cin >> N >> K;

	for(int i=1; i<=N; i++){
		int a, b;
		cin >> a >> b;
		if(mp.count(a)==0){
			mp[a] = b;
		}
		else{
			int c = mp[a];
			mp[a] = c + b;
		}
	}

	int ans = 0;
	long long count = 0;
	for(auto itr = mp.begin(); itr != mp.end(); itr++){
		ans = itr->first;
		count += (long long)itr->second;
		if(count >= K){ break; }
	}
	cout << ans << endl ;
	return 0;
}