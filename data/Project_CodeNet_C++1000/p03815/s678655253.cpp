
// Problem : C - X: Yet Another Die Game
// Contest : AtCoder - AtCoder Beginner Contest 053
// URL : https://atcoder.jp/contests/abc053/tasks/arc068_a
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

#define spc ' '
#define endl '\n'

using namespace std;


int main(){
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long x, ans = 0;
	cin >> x;
	ans = 2*(x/11);
	x%=11;
	if(x<=6 && x!=0)ans++;
	else if(x<11 && x!=0)ans+=2;
	cout << ans;
	return 0;
}