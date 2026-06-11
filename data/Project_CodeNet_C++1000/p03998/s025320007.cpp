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

string SA, SB, SC;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> SA;
	cin >> SB;
	cin >> SC;

	int i=0, j=0, k=0, win=0;
	char c = SA[0];
	i++;
	while(true){
		if(c == 'a'){
			if(i >= SA.size()){
				win = 1;
				break;
			}
			c = SA[i];
			i++;
		}
		else if(c == 'b'){
			if(j >= SB.size()){
				win = 2;
				break;
			}
			c = SB[j];
			j++;
		}
		else if(c == 'c'){
			if(k >= SC.size()){
				win = 3;
				break;
			}
			c = SC[k];
			k++;
		}
	}
	if(win == 1){
		printf("A\n");
	}
	else if(win == 2){
		printf("B\n");
	}
	else if(win == 3){
		printf("C\n");
	}
	return 0;
}