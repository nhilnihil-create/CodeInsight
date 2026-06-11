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

int A, B, C, D, E, F;

int dp[3000+2] = {0}; // 0 未, 1不可, 2可能

int possibleWater(int water){
	int ret = 1;
	if(dp[water] != 0){
		return dp[water];
	}
	for(int i=0; (100 * A * i) <= F; i++){
		for(int j=0; (100 * B * j) <= F; j++){
			int tmp = (100 * A * i) + (100 * B * j) ;
			if(tmp <= F)
				dp[tmp] = 2;
			if(water == tmp){
				ret = 2;
				break;
			}
		}
		if(ret == 2){
			break;
		}
	}
	if(water <= F){
		dp[water] = ret;
	}
	return ret;
}

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> A >> B >> C >> D >> E >> F;
	
	// 水 100A g : x回 
	// 水 100B g : y回 
	// さとう C g : u 回
	// さとう D g : v 回
	int water, water1;
	int sugar, sugar1;
	water1 = 100 * A , sugar1 = 0;
	for(water = 100; water <= F; water += 100){
		if(possibleWater(water) != 2) continue;
		int water2 = 100 * A, sugar2 = 0;
		int k = water / 100;
		int u, v;
		for(v = 0; (D * v) <= F - water; v++){
			for(u = 0; (C * u) <= F - water - (D * v); u++){
				sugar = (C * u) + (D * v);
				if( sugar > (E * k) ) continue;
				if((water + sugar) > F) continue;
				if( (sugar + C) <= E * k && (sugar + C + water) <=F){
					u = u + 1;
					sugar = sugar + C;
				}
				if(sugar * (100 + E) > E * (sugar + water)) continue;
				if(sugar2 * (water + sugar) <= sugar * (water2 + sugar2)){
					sugar2 = sugar;
					water2 = water;
				}
			}
		}
		if(sugar1 * (water2 + sugar2) <= sugar2 * (water1 + sugar1)){
			water1 = water2;
			sugar1 = sugar2;
		}
	}
	printf("%d %d\n", water1+sugar1, sugar1);
	return 0;
}