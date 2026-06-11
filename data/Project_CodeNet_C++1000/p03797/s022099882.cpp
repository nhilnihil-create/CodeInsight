
// Problem : C - Scc Puzzle
// Contest : AtCoder - AtCoder Beginner Contest 055
// URL : https://atcoder.jp/contests/abc055/tasks/arc069_a
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

#define spc ' '
#define endl '\n'

using namespace std;


int main(){
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	unsigned long long n, m;
	cin >> n >> m;
	if(n>=m){
	    cout << m/2;
	}
	else{
	    m-=n*2;
	    cout <<  n + m/4;
	}
	return 0;
}