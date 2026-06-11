
// Problem : C - Back and Forth
// Contest : AtCoder -  AtCoder Beginner Contest 051
// URL : https://atcoder.jp/contests/abc051/tasks/abc051_c
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

#define spc ' '
#define endl '\n'

using namespace std;


int main(){
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	x2 -=x1;
	y2 -=y1;
    x1 = 0;
	y1 = 0;
	for(int i = 0; i < y2; i++){
	    cout << 'U';
	}
	for(int i = 0; i < x2; i++){
	    cout << 'R';
	}
	for(int i = 0; i < y2; i++){
	    cout << 'D';
	}
	for(int i = 0; i < x2; i++){
	    cout << 'L';
	}
	cout << 'L';
	for(int i = 0; i <= y2; i++){
	    cout << 'U';
	}
	for(int i = 0; i <= x2; i++){
	    cout << 'R';
	}
	cout << 'D';
	cout << 'R';
	for(int i = 0; i <= y2; i++){
	    cout << 'D';
	}
	for(int i = 0; i <= x2; i++){
	    cout << 'L';
	}
	cout << 'U';
	return 0;
}