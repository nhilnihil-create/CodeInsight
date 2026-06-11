#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, N) for(int i = 0; i < N; i++)
#define rep2(i, N, a, b) for(int i = a; i < N; i += b)

int main(){
	string s;
	cin >> s;
	map<char, bool> dict;

	for(char c: s) dict[c] = true;
	rep(i, 26){
		char c = 'a' + i;
		if(!dict.count(c)){
			cout << c << endl;
			return 0;
		}
	}
	cout << "None" << endl;
}