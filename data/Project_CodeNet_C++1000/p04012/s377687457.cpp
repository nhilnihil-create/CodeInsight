#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>
#include <numeric>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
int INF = 1e9;

int main(){
	string w;cin >> w;
	vector<int> cnt(26,0);
	for(char ch:w){
		cnt[ch-'a']++;
	}
	rep(i,26){
		if(cnt[i]%2) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;

} 
 