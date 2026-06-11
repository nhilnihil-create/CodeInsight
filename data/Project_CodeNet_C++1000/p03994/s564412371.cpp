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
using Graph = vector<vector<int>>;

typedef long long LL;
static LL INF = (1LL<<62);
static char ALPHA[27] = "abcdefghijklmnopqrstuvwxyz";

int stepAlpha(char x, char y){
	if(x == y) return 0;
	int ret = 0;
	unsigned char u = x;
	unsigned char v = y;
	if(v >= u){
		ret = v - u;
	}
	else{
		ret = stepAlpha(x, 'z') + 1;
		ret += stepAlpha('a', y);
	}
	return ret;
}


int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	string s;
	LL K;
	cin >> s;
	cin >> K;

	int i=0;
	while(true){
		int t = stepAlpha(s[i], 'a');
		if(t <= K){
			s[i] = 'a';
			K -= t;
		}
		i++;
		if(i >= s.size()){
			break;
		}
	}
	LL r = K % 26;
	int pos = s[s.size()-1] - 'a';
	pos += r;
	if(pos > 25){
		pos -= 26;
	}
	s[s.size()-1] = ALPHA[pos];
	printf("%s\n", s.c_str());
	return 0;
}

