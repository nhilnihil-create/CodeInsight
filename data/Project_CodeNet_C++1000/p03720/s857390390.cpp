#include<iostream> 
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
	int n, m, x = 0, j=0,i=0;
	
	cin >> n >> m;
	vector <int>a(m), b(m), ans(n, 0);
	rep(i, m) {
		cin >> a.at(i) >> b.at(i);
	}
	rep(i, m) {
		ans.at(a.at(i) - 1) += 1;
		ans.at(b.at(i) - 1) += 1;
	}
	rep(i, n) {
		cout << ans.at(i) << endl;
	}
	return 0;
}

