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
	int a, z;
	for(int i=0; i<s.size(); i++){
		if(s[i] == 'A'){
			a = i;
			break;
		}
	}
	for(int i=s.size()-1; i>=0; i--){
		if(s[i] == 'Z'){
			z = i;
			break;
		}
	}
	int ans = z - a + 1;
	printf("%d\n", ans);
	return 0;
}
