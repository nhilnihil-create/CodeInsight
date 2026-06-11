#include<bits/stdc++.h>
#define INF 2000000000
#define MOD 1000000007
#define EPS (1e-10)

using namespace std;

int main(int argc, char *argv[]) {
	
	int n; cin >> n;
	int idx = 1;

	vector<int> b;
	if (n % 2 != 0) {
		idx = -1;	
	}

	for (int i = 0; i < n; i++) {
		int a; cin >> a;

		if (idx == 1) {
			b.push_back(a);									
		}else {
			b.insert(b.begin(), a);	
		}
		idx *= -1;
	}


	for (int i = 0; i < n; i++) {
		cout << b[i];
		if (i != n - 1) {
			cout <<  " ";
		}
	}
	cout << endl;

	return 0;
}
