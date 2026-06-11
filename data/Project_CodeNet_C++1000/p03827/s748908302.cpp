#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int N;
	string S;
	cin >> N >> S;
	int x = 0, xmax = 0;
	rep(i,N) {
		if (S[i] == 'I') x++;
		if (S[i] == 'D') x--;
		xmax = max(xmax,x);
	}
	cout << xmax << endl;
	return 0;
}
