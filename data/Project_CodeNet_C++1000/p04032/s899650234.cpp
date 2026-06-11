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
	if(s.size()==2){
		if(s[0]==s[1]) cout << 1 << " " << 2 << endl;
		else cout << -1 << " " << -1 << endl;
		return 0;
	}
	rep(i,s.size()-2){
		if(s[i]==s[i+1]){
			cout << i+1 << " " << i+2 << endl;
			return 0;
		}else if(s[i]==s[i+2]){
			cout << i+1 << " " << i+3 << endl;
			return 0;
		}else if(s[i+1]==s[i+2]){
			cout << i+2 << " " << i+3 << endl;
			return 0;
		}
	}
	printf("-1 -1\n");
	return 0;
} 
 