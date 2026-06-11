#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)

int main(){
	string s;
	cin >> s;
	rep(i, s.size()){
		if(i%2 == 0)
			cout << s.at(i);
		else
			continue;
	}
	cout << endl;
}