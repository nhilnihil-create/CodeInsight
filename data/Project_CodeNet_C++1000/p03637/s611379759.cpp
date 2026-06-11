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

long long N;
vector<long long> a;
vector<int> r;
map<int, int> mp;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for(int i=0; i<N; i++){
		long long v;
		cin >> v;
		a.push_back(v);
		int u = v % 4;
		r.push_back(u);
		if(mp.count(u)==0){
			mp[u] = 1;
		}
		else{
			mp[u]++;
		}
	}

	int ok = 0;
	if(mp.count(0) == 0){
		//余り0がない場合
		if(mp.count(1) != 0 || mp.count(3) != 0){
			ok = 0;
		}
		else{ //余り2のみ。OK
			ok = 1;
		}
	}
	else{
		//余り0がある場合
		if(mp[2] > 0){
			//余り2がある場合、余り2をすべて最後に詰めて、その直前に0、その前は1,3を0で挟めればよい
			if(mp[0] >= mp[1] + mp[3]){
				ok = 1;
			}
			else{
				ok = 0;
			}
		}
		else{
			//余り2がない場合、1,3の間に0で挟めればよい
			if(mp[0] >= mp[1] + mp[3] - 1){
				ok = 1;
			}
			else{
				ok = 0;
			}
		}
	}
	if(ok == 1)
		printf("Yes\n");
	else
		printf("No\n");

	return 0;
}