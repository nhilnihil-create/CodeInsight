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
	int n,l;cin >> n >> l;
	multiset<string> se;
	rep(i,n) {
		string s;cin >> s;
		se.insert(s);
	}
	string ans = "";
	for(string s:se){
		ans += s;
	}
	cout << ans << endl;
}
 
 