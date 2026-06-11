
// Problem : B - Painting Balls with AtCoDeer
// Contest : AtCoder - AtCoder Beginner Contest 046
// URL : https://atcoder.jp/contests/abc046/tasks/abc046_b
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

#define spc ' '
#define endl '\n'

using namespace std;


int main(){
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n >> k;
	long long ans = k;
	for(int i = 0; i < n; i++){
	    if(i==0) continue;
	    ans*=k-1;
	}
	cout << ans;
	return 0;
}