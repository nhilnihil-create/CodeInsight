#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	string O, E;
	cin >> O >> E;
	rep(i,E.size()){
		cout << O[i] << E[i];
	}
	if (O.size()-E.size() == 1) cout << O.back() << endl;
	else cout << endl;
	return 0;
}
