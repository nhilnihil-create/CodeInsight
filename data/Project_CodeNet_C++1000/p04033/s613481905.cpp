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

	LL a, b;
	cin >> a >> b;

	int negative=0, positive=0, zero=0;
	for(int i=a; i<=b; i++){
		if(i < 0){
			negative++;
		}
		else if(i == 0){
			zero++;
		}
		else{
			break;
		}
	}

	if(zero > 0){
		printf("Zero\n");
	}
	else if((negative % 2) == 1){
		printf("Negative\n");
	}
	else{
		printf("Positive\n");
	}
	return 0;
}