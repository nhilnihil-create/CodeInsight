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

	int W, H, N;
	vector<int> X0, X1, Y0, Y1;

	cin >> W >> H >> N;
	for(int i=0; i<N; i++){
		int x, y, a;
		cin >> x >> y >> a;
		if(a == 1){ X0.push_back(x);}
		else if(a == 2){ X1.push_back(x);}
		else if(a == 3){ Y0.push_back(y);}
		else if(a == 4){ Y1.push_back(y);}
	}

	int x0 = - 1, x1 = W+1, y0 = -1, y1 = H+1;
	if(X0.size() > 0){
		sort(X0.begin(), X0.end());
		x0 = X0[X0.size()-1];
	}
	if(X1.size() > 0){
		sort(X1.begin(), X1.end());
		x1 = X1[0];
	}
	if(Y0.size() > 0){
		sort(Y0.begin(), Y0.end());
		y0 = Y0[Y0.size()-1];
	}
	if(Y1.size() > 0){
		sort(Y1.begin(), Y1.end());
		y1 = Y1[0];
	}

	int ans = 0;
	for(int i=1; i<=W; i++){
		for(int j=1; j<=H; j++){
			if(x0 < i && i <= x1 && y0 < j && j <= y1){
				ans++;
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}

