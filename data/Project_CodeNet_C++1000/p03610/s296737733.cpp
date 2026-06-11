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

	string s;
	cin >> s;

	for(int i=0; i<s.size(); i++){
		char c = s[i];
		if((i % 2) == 0){
			printf("%c", c);
		}
	}
	printf("\n");
	return 0;
}