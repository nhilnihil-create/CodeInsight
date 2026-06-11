#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, N) for(int i = 0; i < N; i++)
#define rep2(i, N, a, b) for(int i = a; i < N; i += b)

int main(){
	string O, E;
	cin >> O >> E;

	rep(i, (int)(E.size())){
		cout << O.at(i) << E.at(i);
	}
	if (O.size() > E.size()) cout << O.at(O.size() - 1);
	cout << endl;
}