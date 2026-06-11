
// Problem : B - Choose Integers
// Contest : AtCoder - AtCoder Beginner Contest 060
// URL : https://atcoder.jp/contests/abc060/tasks/abc060_b
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

#define spc ' '
#define endl '\n'

using namespace std;


int main(){
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int a, b, c, m;
	cin >> a >> b >>c;
	m = a;
	for(int i=0;i<b;i++){
	    a%=b;
	    if(a==c){
	        cout << "YES";
	        return 0;
	    }
	    a+=m;
	}
	cout << "NO";
	return 0;
}