
// Problem : A - Fighting over Candies
// Contest : AtCoder - AtCoder Beginner Contest 047
// URL : https://atcoder.jp/contests/abc047/tasks/abc047_a
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

#define spc ' '
#define endl '\n'

using namespace std;


int main(){
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	vector<int> v(3);
	for(auto &it:v){
	    cin >> it;
	}
	sort(v.begin(),v.end());
	(v[0]+v[1]==v[2] && cout << "Yes") || cout << "No";
	return 0;
}