#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	string X;
	cin >> X;

	stack<char> s;

	for (int ii = 0; ii < X.size(); ++ii){
		if (s.empty()){
			s.push(X[ii]);
		} else if ( (s.top() == 'S') && (X[ii] == 'T') ){
			s.pop();
		} else {
			s.push(X[ii]);
		}
	}

	int ans = (s.empty()) ? 0 : s.size();

	cout << ans << endl;


	return 0;
}
