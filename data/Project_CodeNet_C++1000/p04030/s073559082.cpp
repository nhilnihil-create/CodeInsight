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
	string ans = "";
	rep(i,s.size()){
		if(s[i]=='0') ans.push_back('0');
		else if(s[i]=='1') ans.push_back('1');
		else if(ans.size()>0) ans = ans.substr(0,ans.size()-1);
	}
	cout << ans << endl;
	
} 
 