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
	int i=0,j=0,n,a,b,an=0,bn=0,cn=0;
	cin >> n>>a>>b;
	vector<char>s(n);
	rep(i, n) {
		cin >> s.at(i);
		if (s.at(i) == 'a') {
			an++;
			
		}
		else if (s.at(i) == 'b') {
			bn++;
			
		}
		else if (s.at(i) == 'c') {
			cout << "No" << endl;
		}
		if (s.at(i) == 'a') {
			if (an + bn <= a + b) {
				cout << "Yes" << endl;
			}
			else {
				cout << "No" << endl;
			}
		}
		else if (s.at(i) == 'b') {
			if (an + bn <= a + b && b >= bn) {
				cout << "Yes" << endl;
			}
			else {
				cout << "No" << endl;
				bn--;
			}
		}

	}
	return 0;
}