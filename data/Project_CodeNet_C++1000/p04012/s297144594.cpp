#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	string w;
	cin >> w;
	int c[26] = {0};
	rep(i,w.size()) c[w[i]-'a']++;
	rep(i,26) {
		if (c[i]%2 == 1) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;

	return 0;
}
