#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, N) for(int i = 0; i < N; i++)
#define rep2(i, N, a, b) for(int i = a; i < N; i += b)

int main(){
	string A, B;
	// int64_t A, B;
	cin >> A >> B;
	// cout << A << endl;
	// cout << B << endl;
	if (A.size() == B.size()){
		if (A > B) cout << "GREATER" << endl;
		else if (A < B) cout << "LESS" << endl;
		else cout << "EQUAL" << endl;
	}
	else {
		if (A.size() > B.size()) cout << "GREATER" << endl;
		else cout << "LESS" << endl;
	}
}