#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  int n; cin >> n;
	string s; cin >> s;
	bool ok = true;
	vector<string> t(4);
	t[0] = "SS"; t[1] = "SW"; t[2] = "WS"; t[3] = "WW";
	for(int i = 0; i < 4; i++){
  	for(int j = 2; j < n; j++){
		  if(t[i][j - 1] == 'S'){
				if(s[j - 1] == 'o') t[i].push_back(t[i][j - 2]);
				if(s[j - 1] == 'x'){
					if(t[i][j - 2] == 'W') t[i].push_back('S');
					if(t[i][j - 2] == 'S') t[i].push_back('W');
				}
			}
			if(t[i][j - 1] == 'W'){
				if(s[j - 1] == 'x') t[i].push_back(t[i][j - 2]);
				if(s[j - 1] == 'o'){
					if(t[i][j - 2] == 'W') t[i].push_back('S');
					if(t[i][j - 2] == 'S') t[i].push_back('W');
				} 
			}
		} 
	}
	for(int i = 0; i < 4; i++){
		ok = true;
		if(s.back() == 'o'){
			if(t[i][n - 1] == 'S' && t[i][n - 2] != t[i][0]) ok = false;
			if(t[i][n - 1] == 'W' && t[i][n - 2] == t[i][0]) ok = false;
		}
		if(s.back() == 'x'){
			if(t[i][n - 1] == 'S' && t[i][n - 2] == t[i][0]) ok = false;
			if(t[i][n - 1] == 'W' && t[i][n - 2] != t[i][0]) ok = false;
		}
		for(int j = n - 3; j >= 0; j--){
			if(s[j + 1] == 'o'){
				if(t[i][j + 1] == 'S' && t[i][j + 2] != t[i][j]) ok = false;
				if(t[i][j + 1] == 'W' && t[i][j + 2] == t[i][j]) ok = false;
			}
			if(s[j + 1] == 'x'){
				if(t[i][j + 1] == 'S' && t[i][j + 2] == t[i][j]) ok = false;
				if(t[i][j + 1] == 'W' && t[i][j + 2] != t[i][j]) ok = false;
			}
		}
		if(s[0] == 'o'){
			if(t[i][0] == 'S' && t[i][1] != t[i][n - 1]) ok = false;
			if(t[i][0] == 'W' && t[i][1] == t[i][n - 1]) ok = false;
		}
		if(s[0] == 'x'){
			if(t[i][0] == 'S' && t[i][1] == t[i][n - 1]) ok = false;
			if(t[i][0] == 'W' && t[i][1] != t[i][n - 1]) ok = false;
		}
		if(ok){
			cout << t[i] << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}