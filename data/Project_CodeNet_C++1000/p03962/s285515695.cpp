#include "bits/stdc++.h"
using namespace std;

int main() {
	set<int>S;
	for (int i = 0;i<3;++i) {
		int num;
		cin >> num;
		S.insert(num);
	}
	cout << S.size()<<endl;
	return 0;
}