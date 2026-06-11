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
typedef long long LL;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int A, B, C;
	cin >> A >> B >> C;
	// A = Bq + r
	int q = A / B;
	int r = A % B;
	int possible = 0;
	for(int s=0; s < B; s++){
		if((r*s - C) % B == 0){
			possible = 1;
			break;
		}
	}
	if(possible == 1){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
	return 0;
}
