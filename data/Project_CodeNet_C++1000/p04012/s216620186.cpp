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
	int i = 0, j = 0,k,m=0;
	vector<int>n(0);
	string s;
	cin >> s;
	k = s.length();
	vector<char>w(k);
	rep(i,k) {
		w.at(i) = s[i];
	}
	rep(i, k) {
		rep(j, k) {
			if (w.at(i) == w.at(j) ){
				m++;
			}
		}
		n.push_back(m);
		m = 0;
	}
	rep(i, n.size()) {
		if (n.at(i) % 2 != 0) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}