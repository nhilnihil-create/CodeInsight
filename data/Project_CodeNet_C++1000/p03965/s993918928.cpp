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
	string s;cin >> s;
	int ans = 0;
	rep(i,s.size()) {
		if(i%2==0) {
			if(s[i]=='p') ans--;
		}
		else {
			if(s[i]=='g') ans++;
		}
	}
	cout << ans << endl;

} 
