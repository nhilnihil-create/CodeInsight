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

int N;
int K;
char D[9+2] = {0};
int  d[9+2] = {0};
vector<int> vd; //嫌いな数字ではない数字

int getNDigit(int x){
	if(x == 0) return 1;
	int u = x;
	int ret = 0;
	while(u > 0){
		ret++;
		u /= 10;
	}
	return ret;
}

//右からn桁目の数字を返す
int getRDigit(int x, int n){
	int u = x;
	int ret = 0;
	for(int i=0; i<n; i++){
		ret = u % 10;
		u = u / 10;
	}
	return ret;
}

//xの各桁がvで構成されている場合に、各桁がvで構成されている次の数を返す
int getNextNumber(vector<int>v, int x){
	int ndx = getNDigit(x);
	int ret = 0, MAX= 0;
	int max = v[v.size()-1];
	for(int i=0; i<ndx; i++){
		MAX += max * ((int)pow(10, i)) ;
	}
	if(x == MAX){
		int c = v[0];
		if(v[0] == 0){
			c = v[1];
		}
		ret = c * ((int)pow(10, ndx));
		for(int i=0; i<ndx; i++){
			ret += v[0] * ((int)pow(10, i));
		}
	}
	for(int i=1; i<=ndx; i++){
		int c = getRDigit(x, i);
		int C = 0;
		if(c == v[v.size()-1]){
			//桁上がり処理
			if(v.size() > 1){
				x = x - (c - v[0]) * ((int)pow(10, i-1));
			}
			continue;
		}
		else{
			for(int j=0; j<v.size()-1; j++){
				if(c == v[j]){
					C = v[j+1];
					break;
				}
			}
			ret = x + (C - c) * ((int)pow(10, i-1));
			break;
		}
	}
	return ret;
}

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	for(int i=1; i<=K; i++){
		char c;
		char s[2] = {0};
		cin >> c;
		s[0] = c;
		D[i] = c;
		d[i] = atoi(s);
	}
	for(int i=0; i<=9; i++){
		int exist = 0;
		for(int j=1; j<=K; j++){
			if(i == d[j]){ exist = 1; }
		}
		if(exist == 0){ vd.push_back(i); }
	}
	sort(vd.begin(), vd.end());
	int nd = getNDigit(N);
	int min = 0;
	for(int i=0; i<nd; i++){
		int c = vd[0];
		if(i == nd - 1 && c == 0){
				c = vd[1];
		}
		min += c * ((int)pow(10, i));
	}
	int ans = min;
	while(ans < N){
		ans = getNextNumber(vd, ans);
	}
	printf("%d\n", ans);
	return 0;
}