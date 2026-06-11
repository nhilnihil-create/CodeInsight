
// Problem : B - ∵∴∵
// Contest : AtCoder - AtCoder Beginner Contest 058
// URL : https://atcoder.jp/contests/abc058/tasks/abc058_b
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

#define spc ' '
#define endl '\n'

using namespace std;


int main(){
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string e, o;
	cin >> o >> e;
	int n = e.size() + o.size();
	for(int i = 0; i < n; i ++){
	    if(i&1){
	        cout << e[i/2];
	    }
	    else{
	        cout << o[i/2];
	    }
	}
	return 0;
}