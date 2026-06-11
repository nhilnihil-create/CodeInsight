#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, N) for(int i = 0; i < N; i++)
#define rep2(i, N, a, b) for(int i = a; i < N; i += b)

int main(){
	string S;
	cin >> S;

	map<char, bool> D;
	rep(i, (int)(S.size())){
		if (S.at(i) == 'N') D['N'] = true;
		if (S.at(i) == 'W') D['W'] = true;
		if (S.at(i) == 'S') D['S'] = true;
		if (S.at(i) == 'E') D['E'] = true;
	}
	if (D['N'] && D['S'] && D['W'] && D['E']) cout << "Yes" << endl;
	else if (D['N'] && D['S'] && !D['W'] && !D['E']) cout << "Yes" << endl;
	else if (!D['N'] && !D['S'] && D['W'] && D['E']) cout << "Yes" << endl;
	else cout << "No" << endl;
}