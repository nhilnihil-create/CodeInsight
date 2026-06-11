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
	vector<string> s(3);cin >> s[0] >> s[1] >> s[2];
	int ind = 0;
	while(true){
		if(s[ind].size()==0) {
			char ans = 'A'+ind;
			cout << ans << endl;
			return 0;
		}
		int next = s[ind][0] - 'a';
		s[ind] = s[ind].substr(1,s[ind].size()-1);
		ind = next;
	}
} 
