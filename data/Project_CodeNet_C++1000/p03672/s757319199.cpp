#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	string S;
	cin >> S;

	int N = S.size();
	if (N%2 == 0) S = S.substr(0,N-2);
	else S = S.substr(0,1);
	while (1) {
		N = S.size();
		string sl = S.substr(0, N/2);
		string sr = S.substr(N/2, N/2);
		if (sl == sr) break;
		S = S.substr(0,N-2);
	}

	cout << N << endl;

	return 0;
}
