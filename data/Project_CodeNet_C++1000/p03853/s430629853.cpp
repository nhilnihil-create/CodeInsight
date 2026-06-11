
// Problem : B - Thin
// Contest : AtCoder - AtCoder Beginner Contest 049
// URL : https://atcoder.jp/contests/abc049/tasks/abc049_b
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

#define spc ' '
#define endl '\n'

using namespace std;


int main(){
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int h, w;
	cin >> h >> w;
	vector<vector<char>> a(h, vector<char> (w)), b(2*h,vector<char> (w));
	for(auto &it:a){
	    for(auto &it2:it){
	        cin >> it2;
	    }
	}
	for(int i = 0; i <2*h; i++){
	    for(int j=0; j<w; j++){
	        b[i][j] = a[(i+2)/2 -1][j];
	    }
	}
	for(vector<char> s:b){
	    for(char c:s){
	        cout << c;
	    }
	    cout << endl;
	}
	return 0;
}