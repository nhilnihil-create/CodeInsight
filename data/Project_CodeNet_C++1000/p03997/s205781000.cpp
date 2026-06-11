
// Problem : A - Trapezoids
// Contest : AtCoder - AtCoder Beginner Contest 045
// URL : https://atcoder.jp/contests/abc045/tasks/abc045_a
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

#define spc ' '
#define endl '\n'

using namespace std;


int main(){
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int a,b,h;
	cin>>a>>b>>h;
	cout<<(a+b)/2.0*h;
	return 0;
}