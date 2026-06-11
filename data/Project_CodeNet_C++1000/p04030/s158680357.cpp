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
	string v;
	cin >> s;

	for(int i=0; i<s.size(); i++){
		if(s[i] == 'B'){
			if(v.size() != 0){
				v.pop_back();
			}
		}
		else{
			v.push_back(s[i]);
		}
	}

	printf("%s\n", v.c_str());
	return 0;
}