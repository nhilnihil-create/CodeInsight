
// Problem : A - Tak and Hotels (ABC Edit)
// Contest : AtCoder - AtCoder Beginner Contest 044
// URL : https://atcoder.jp/contests/abc044/tasks/abc044_a
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

#define spc ' '
#define endl '\n'

using namespace std;


int main(){
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, k, x, y;
	cin >> n>> k >> x>>y;
	cout << min(n,k)*x + max(0,n-k)*y;
	return 0;
}